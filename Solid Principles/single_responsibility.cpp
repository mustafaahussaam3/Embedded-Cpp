/*
                    Single-Reponsibility 

A class should have one, and only one, reason to change.
An object should have only one responibility(a reason to change). it is supposed to 

1. Simplify modifications. 
2. Cohesion is stronger. (Robust)(function are all depend on itself with its data members and functions)
3. Dependency coupling is looser. (no tide coupling between classes )
4. Code is less complex. (Easy understand, Organized)
5. Solving bugs easy.(Easy Test)
6. Divide and Conquer
    ex: garden cheif robot

                                                                                                        \------------------------\
We need to solve by Solid Principles some issues in the Software Enviroment such that: (design smells) Class -> Class -> Constuctor 

1. Rigidity and not Flexible
    // (That every change cause cascade of related changes.)
2. Fragility
    // (Distant and apparently unrelated code breaks and bugs after every change) ex. Comm Wires
3. Immoble 
    //(Code is helplessly entangled, you can't reuse) ex: 2 Dolls 
4. Viscous 
    //(Behaving badly in the most attractive alternative) ex: Broken Window Theory --> Making Hack is not a clean code 

Summary: Clean Code is the Number of WTF's/Min :DD

Reference: Robotic Corner 
EditedBy: Mustafa Hussam Eldin 

*/


#include <ostream>
#include <string>
#include <vector>
#include <fstream> //file stream and is inherted from iostream 

struct IJournal
{
	std::string m_title;
	std::vector<std::string> m_entries;
	virtual void add(const std::string& entry) = 0;
};

struct Journal :public IJournal
{
	/// <summary>
	/// The Private or Public members in C++
	///
	/// </summary>
	std::string m_title;
	std::vector<std::string> m_entries;
	explicit Journal(const std::string& title)
		: m_title (title)
	{
		//m_title = title;
	}

	void add(const std::string& entry) 
	{
		m_entries.push_back(entry);
	}
	/// <summary>
	///  not single Responsablity
	///
	/// </summary>
	/// <param name="filename">The file name to save entries </param>
	// void save(const std::string& filename)
	// {
	// 	std::ofstream ofs(filename); //creating object ofs from class ofstream(output file stream) to write on the filename we take 
	// 	for (auto& s : m_entries)
	// 		ofs << s.c_str() << std::endl; //converting the class string type to c-ctyle character string that the ofstream can read 
	// }
};

struct JournalSport : public IJournal
{
	
	explicit JournalSport(const std::string& title)
	{
		m_title = title;
	}

	void add(const std::string& entry) override
	{
		m_entries.push_back(entry);
	}
	/// <summary>
	///  not single Responsablity
	///
	/// </summary>
	/// <param name="filename">The file name to save entries </param>
	// void save(const std::string& filename)
	// {
	// 	std::ofstream ofs(filename);
	// 	for (auto& s : m_entries)
	// 		ofs << s.c_str() << std::endl;

	// }
};

struct PrintEntirsManager
{
	/// <summary>
	/// static function for call the save operation 
	/// </summary>
	/// <param name="j"></param>
	/// <param name="filename"></param>
	static void save(const Journal& j, const std::string& filename)
	{
		std::ofstream ofs(filename);
		for (auto& s : j.m_entries)
			ofs << s.c_str() << std::endl;
	}

};


auto main(int  argc,char** argv)-> int
{
	Journal Alahram{ "Alahram" };
	//JournalSport Alahly{ "AlAhly" };

	Alahram.add("There is was a visit for the prime minstar of Egypt to india");
	Alahram.add("Hello From elAhram");
	//Alahly.add("Alahly wining the third place in the worl cup");

	PrintEntirsManager::save(Alahram, "AlahramXML");
	//PrintEntirsManager::save(Alahly,"Al-Ahly");

	return 1;
}

