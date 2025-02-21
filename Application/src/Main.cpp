#include <iostream>

#include <Photon/Color/Color.hpp>
#include <Photon/Files/PPMFile.hpp>

int main(int argc, char **argv)
{
    // Image
    const int imageWidth = 256;
    const int imageHeight = 256;

    Photon::PPMFile file("image.ppm", imageWidth, imageHeight, Photon::PPM_FORMAT::P3);

    if (!file.Open())
    {
        std::cerr << "Failed to open/create the output file" << std::endl;
        return -1;
    }

    // Render
    std::vector<Photon::Color> imageBuffer;
    for (int j = 0; j < imageHeight; j++)
    {
        std::cout << "\rScanlines Remaining: " << (imageHeight - j) << ' ' << std::flush;
        for (int i = 0; i < imageWidth; i++)
        {
            double r = static_cast<double>(i) / (imageWidth - 1);
            double g = static_cast<double>(j) / (imageHeight - 1);
            double b = 0.0;

            Photon::Color color(r, g, b);
            imageBuffer.push_back(color);
        }
    }

    std::cout << "\nRender Complete" << std::endl;
    file.Save(imageBuffer);
    file.Close();

    return 0;
}