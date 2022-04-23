class Sfml < Formula
  # Don't update SFML until there's a corresponding CSFML release
  desc "Multi-media library with bindings for multiple languages"
  homepage "https://www.sfml-dev.org/"
  url "https://www.sfml-dev.org/files/SFML-2.5.1-sources.zip"
  sha256 "bf1e0643acb92369b24572b703473af60bac82caf5af61e77c063b779471bb7f"
  license "Zlib"
  revision 1
  head "https://github.com/SFML/SFML.git", branch: "master"

  depends_on "cmake" => :build
  depends_on "doxygen" => :build
  depends_on "flac"
  depends_on "freetype"
  depends_on "jpeg"
  depends_on "libogg"
  depends_on "libvorbis"

  on_linux do
    depends_on "libx11"
    depends_on "libxrandr"
    depends_on "mesa"
    depends_on "mesa-glu"
    depends_on "openal-soft"
    depends_on "systemd"
  end

  # https://github.com/Homebrew/homebrew/issues/40301

  def install
    # error: expected function body after function declarator
    ENV["SDKROOT"] = MacOS.sdk_path if MacOS.version == :sierra

    # Always remove the "extlibs" to avoid install_name_tool failure
    # (https://github.com/Homebrew/homebrew/pull/35279) but leave the
    # headers that were moved there in https://github.com/SFML/SFML/pull/795
    rm_rf Dir["extlibs/*"] - ["extlibs/headers"]

    args = ["-DCMAKE_INSTALL_RPATH=#{opt_lib}",
            "-DSFML_MISC_INSTALL_PREFIX=#{share}/SFML",
            "-DSFML_INSTALL_PKGCONFIG_FILES=TRUE",
            "-DSFML_BUILD_DOC=TRUE"]

    args << "-DSFML_USE_SYSTEM_DEPS=ON" if OS.linux?

    system "cmake", ".", *std_cmake_args, *args
    system "make", "install"
  end

  test do
    (testpath/"test.cpp").write <<~EOS
      #include "Time.hpp"
      int main() {
        sf::Time t1 = sf::milliseconds(10);
        return 0;
      }
    EOS
    system ENV.cxx, "-I#{include}/SFML/System", testpath/"test.cpp",
           "-L#{lib}", "-lsfml-system", "-o", "test"
    system "./test"
  end
end
