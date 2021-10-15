#include <iostream>

struct Database
{
    /**
     * \brief Please do not create more than one instance.
     */
    
protected:
    Database() {}

public:
    static Database& get()
    {
        // thread -safe in C++11
        // static Database database;

        // Create database in heap memory
        // Make sure that Database lives until the end of the program
        static Database* database = new Database();
        return *database;
    }

    Database(Database const&) = delete;
    Database(Database&&) = delete;
    Database& operator=(Database const&) = delete;
    Database& operator=(Database &&) = delete;

    // {
    //     static int instance_count{ 0 };
    //     if (++instance_count > 1) 
    //         throw std::exception("Cannot make >1 database!");
    // }
};

// static Database database{};

// Database& get_database()
// {
//     static Database database;
//     return database;
// }