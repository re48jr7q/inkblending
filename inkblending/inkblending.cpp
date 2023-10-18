#include <iostream>
#include <string>
#include <string_view>

class ColourNameAndValue
{
private:
	long m_pmsNr{};
	std::string m_cName1{};
	double m_cValue1{};
	std::string m_cName2{};
	double m_cValue2{};
	std::string m_cName3{};
	double m_cValue3{};
	std::string m_cName4{};
	double m_cValue4{};
	std::string m_cName5{};
	double m_cValue5{};

public:
	ColourNameAndValue(long pmsNr = 0
		, std::string_view cName1 = " ", double cValue1 = 0.0
		, std::string_view cName2 = " ", double cValue2 = 0.0
		, std::string_view cName3 = " ", double cValue3 = 0.0
		, std::string_view cName4 = " ", double cValue4 = 0.0
		, std::string_view cName5 = " ", double cValue5 = 0.0)
		: m_pmsNr{ pmsNr }, m_cName1 {cName1}, m_cValue1{ cValue1 }
		, m_cName2{ cName2 }, m_cValue2{ cValue2 }, m_cName3{ cName3 }
		, m_cValue3{ cValue3 }, m_cName4{ cName4 }, m_cValue4{ cValue4 }
		, m_cName5{ cName5 }, m_cValue5{ cValue5 } {}

	long getPmsNr()const { return m_pmsNr; }
	const std::string& getcName1()const { return m_cName1; }
	double getcValue1()const { return m_cValue1; }
	const std::string& getcName2()const { return m_cName2; }
	double getcValue2()const { return m_cValue2; }
	const std::string& getcName3()const { return m_cName3; }
	double getcValue3()const { return m_cValue3; }
	const std::string& getcName4()const { return m_cName4; }
	double getcValue4()const { return m_cValue4; }
	const std::string& getcName5()const { return m_cName5; }
	double getcValue5()const { return m_cValue5; }

	friend std::ostream& operator<<(std::ostream& out, const ColourNameAndValue C);
};

class PmsContainer
{
private:
	static ColourNameAndValue s_nr[4];

public:
	PmsContainer() = delete;

	static ColourNameAndValue* getNr(long pmsNr)
	{
		for (int count{ 0 }; count < 4; ++count)
		{
			if (s_nr[count].getPmsNr() == pmsNr)
			{
				return &(s_nr[count]);
			}
		}
		return nullptr;
	}
};

std::ostream& operator<<(std::ostream& out, const ColourNameAndValue C)
{
	out << C.m_pmsNr << '\n';
	out << C.m_cName1 << '\n';
	out << C.m_cValue1 << '\n';
	out << C.m_cName2 << '\n';
	out << C.m_cValue2 << '\n';
	out << C.m_cName3 << '\n';
	out << C.m_cValue3 << '\n';
	out << C.m_cName3 << '\n';
	out << C.m_cValue3 << '\n';
	out << C.m_cName4 << '\n';
	out << C.m_cValue4 << '\n';
	out << C.m_cName5 << '\n';
	out << C.m_cValue5 << '\n';
	return out;
}

ColourNameAndValue PmsContainer::s_nr[4]{
	{368,"yellow",75.0,"pro.blue",25.0," ",0.0," ",0.0," ",0.0},
	{200,"rubine red",50.5,"warm red",30.5,"black",10.0," ",0.0," ",0.0},
	{100,"yellow",50.0,"white",50.0," ",0.0," ",0.0," ",0.0},
	{186,"rubine red",40.4,"warm red",20.6,"red 031",15.0,"black",5.0," ",0.0}
};

long getPmsNr()
{
	std::cout << "PMS: ";
	long pms{};
	std::cin >> pms;
	return pms;
}

long getMixQuantity()
{
	std::cout << "Aantal grammen: ";
	long gram{};
	std::cin >> gram;
	return gram;
}

void printColourMix(const ColourNameAndValue* c, long m)
{
	std::cout << "PMS kleur: " << c->getPmsNr() << '\n\n';
	std::cout << c->getcName1() << '\t' << (c->getcValue1() / 100) * m << '\n';
	std::cout << c->getcName2() << '\t' << (c->getcValue2() / 100) * m << '\n';
	if (c->getcValue3() == 0.0)
		return;
	std::cout << c->getcName3() << '\t' << (c->getcValue3() / 100) * m << '\n';
	if (c->getcValue4() == 0.0)
		return;
	std::cout << c->getcName4() << '\t' << (c->getcValue4() / 100) * m << '\n';
	if (c->getcValue5() == 0.0)
		return;
	std::cout << c->getcName5() << '\t' << (c->getcValue5() / 100) * m << '\n';
}

int main()
{
	ColourNameAndValue* colour{ PmsContainer::getNr(getPmsNr()) };
	long mix{ getMixQuantity() };
	printColourMix(colour, mix);

	return 0;
}