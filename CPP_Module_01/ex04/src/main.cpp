#include <iostream>
#include <fstream>


std::string new_replace(std::string buffer, const std::string replace , const std::string search)
{
    size_t erase_length = search.length();
    size_t replace_length = replace.length();
    size_t index_search = buffer.find(search);

    while(index_search != std::string::npos)
    {
        buffer.erase(index_search, erase_length);
        buffer.insert(index_search, replace);
        index_search = buffer.find(search, index_search + replace_length);
    }
    return(buffer);
}


int main(int ac, char **av)
{
    if(ac != 4)
    {
        std::cout << "wrong number of arguments\n" <<
        "Usage:\t./replace <file_name> <search> <replace>" << std::endl;
    }
    else
    {
        std::string filename = av[1];
        std::string search   = av[2];
        std::string replace  = av[3];

        std::string          buffer;
        std::ifstream        infile;
        std::ofstream        outfile;
    
        infile.open(filename.c_str());
        if(infile.is_open() == true)
        {
            std::string fulloutfilename = std::string(filename) + "replace";
            outfile.open(fulloutfilename.c_str(), std::ios::out | std::ios::trunc);
            if(outfile.is_open() == true)
            {
                while(std::getline(infile, buffer))
                {
                    buffer = new_replace(buffer, replace, search);
                    outfile << buffer;
                    if(infile.peek() != EOF)
                        outfile << std::endl;
                }
                outfile.close();
            }
            else
            {
                std::perror("Outfile:");
                infile.close();
                return(1);
            }
            infile.close();
        }
        else
        {
            std::perror("Infile:");
            return(1);
        }
    }
    return(0);
}