#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    // Image
    const int imageWidth = 256;
    const int imageHeight = 256;

    std::ofstream file;
    file.open("image.ppm");

    if (!file.is_open())
    {
        std::cerr << "Failed to open/create the output file" << std::endl;
    }

    // Render
    file << "P3" << std::endl
         << imageWidth << ' ' << imageHeight << std::endl
         << "255" << std::endl;

    for (int j = 0; j < imageHeight; j++)
    {
        std::cout << "\rScanlines Remaining: " << (imageHeight - j) << ' ' << std::flush;
        for (int i = 0; i < imageWidth; i++)
        {
            double r = static_cast<double>(i) / (imageWidth - 1);
            double g = static_cast<double>(j) / (imageHeight - 1);
            double b = 0.0;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            file << ir << ' ' << ig << ' ' << ib << std::endl;
        }
    }

    std::cout << "\nRender Complete" << std::endl;
    file.close();

    return 0;
}