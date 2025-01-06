#ifndef FILE_H
#define FILE_H

#include<string>

namespace fs {

    class File{
    /* Represent a file with a name and size.
     * Files are not owned by any directory 
     * but are dynamically allocated
     * (simulating real-world scenarios).    */
     
    public:
    File(std::string a_name, size_t a_size)
        :name{a_name}, size{a_size} {}
    
    std::string get_name() const{ return name; }
    size_t get_size() const { return size; }

    std::string get_info(){
        return "File: " + name + " (" + std::to_string(size)  +  " bytes)";
    }

    private:
        std::string name;
        size_t size;
    };


    std::ostream& operator<<(std::ostream& os, const File& f){
        return os<< "File: " << f.get_name() << " (" << f.get_size() << " bytes)";
    }

}   // fs namespace

#endif /* FILE_H */
