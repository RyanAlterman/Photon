#include "Files/File.hpp"

namespace Photon
{
    File::File(std::string path)
    {
        m_path = path;
    }

    File::~File()
    {
        // NOTE: Currently does nothing
    }

    bool File::Open()
    {
        m_file.open(m_path);
        return m_file.is_open();
    }

    void File::Close()
    {
        m_file.close();
    }

    bool File::IsOpen()
    {
        return m_file.is_open();
    }
}