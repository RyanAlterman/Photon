#pragma once

#include "../Color/Color.hpp"

#include <vector>
#include <fstream>
#include <string>

namespace Photon
{
    // TODO: Doc Comments
    class File
    {
    public:
        File(std::string path);
        ~File();

        bool Open();
        void Close();

        bool IsOpen();

        virtual bool Save(std::vector<Color> buffer) = 0;

    protected:
        std::string m_path;
        std::ofstream m_file;

    private:
    };
}