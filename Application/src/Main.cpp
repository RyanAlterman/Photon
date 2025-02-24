#include <iostream>

#include <Photon/Color/Color.hpp>
#include <Photon/Files/PPMFile.hpp>
#include <Photon/Collision/Ray.hpp>

Photon::Color rayColor(const Photon::Ray &r)
{
    Photon::Vector dir(r.Direction());

    Photon::Vector unitDirection = dir.Normalize();
    double a = 0.5 * (unitDirection.GetY() + 1.0);
    return (1.0 - a) * Photon::Color(1.0, 1.0, 1.0) + a * Photon::Color(0.5, 0.7, 1.0);
}

int main(int argc, char **argv)
{
    // Image
    double aspectRatio = 16.0 / 9.0;

    const int imageWidth = 400;
    int imageHeight = (int)(imageWidth / aspectRatio);
    imageHeight = (imageHeight < 1) ? 1 : imageHeight; // Ensure the image has at least 1 pixel in height

    // Camera
    double focalLength = 1.0;
    double viewportHeight = 2.0;
    double viewportWidth = viewportHeight * ((double)(imageWidth / imageHeight));
    Photon::Point cameraCenter = Photon::Point();

    // Calculate the Vectors accross horizontal and vertical viewport edges
    Photon::Vector viewportU = Photon::Vector(viewportWidth);
    Photon::Vector viewportV = Photon::Vector(0.0, -viewportHeight);

    // Calculate horizontal and vertical deltas
    Photon::Vector pixelDeltaU = viewportU / imageWidth;
    Photon::Vector pixelDeltaV = viewportV / imageHeight;

    // Calculate location of uppper left pixel
    Photon::Point viewportUpperLeft = cameraCenter - Photon::Vector(0, 0, focalLength) - viewportU / 2 - viewportV / 2;
    Photon::Point pixel00Loc = viewportUpperLeft + 0.5 * (pixelDeltaU + pixelDeltaV);

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
            Photon::Point pixelCenter = pixel00Loc + (i * pixelDeltaU) + (j * pixelDeltaV);
            Photon::Vector rayDirection = pixelCenter - cameraCenter;
            Photon::Ray r(cameraCenter, rayDirection);

            Photon::Color pixelColor = rayColor(r);
            imageBuffer.push_back(pixelColor);
        }
    }

    std::cout << "\nRender Complete" << std::endl;
    file.Save(imageBuffer);
    file.Close();

    return 0;
}