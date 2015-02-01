#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

/*Pirmojoje eilutėje pateikiamas testinių atvejų skaičius T (T ≤ 100). 
Pirmojoje kiekvieno testinio atvejo eilutėje nurodytas e. pašto adresų 
skaičius duomenų bazėje n ir vartotojo užklausų skaičius m (1 ≤ n, m ≤ 10). 
Kitose n eilučių pateikiami e. pašto adresai, esantys duomenų bazėje 
(tik mažosios lotynų kalbos raidės, skaitmenys ir simboliai „@“, „.“). 
Kitose m eilučių yra pateikiami adresai, kuriuos programa bando surasti 
(tik mažosios lotynų kalbos raidės, skaitmenys ir simboliai „@“, „.“).

Pastaba: e. pašto adresų ilgis nėra ilgesnis nei 100.*/

void toCharArr(std::string ieskauStr, char (&ieskau)[100]);
bool findMail(std::string ieskauStr, const std::vector<std::string> & dataBase); //Iesko duotojo email duomenu bazeje.
int main(){
    int t = 0; //Testiniu atveju skaicius
    std::cin >> t;
    int n = 0; //E pasto adresai duomenu bazeje.
	int m = 0; //Vartotojo uzklausu skaicius
    std::vector<std::string> dataBase;
    std::string elDuomenuBazeje;
	std::string ieskauStr;
    for (int casee = 1; casee <= t; casee++){
    	dataBase.clear();
    	std::cin >> n;
    	std::cin >> m;
    	std::cout << "Case #" << casee << ":\n";
	    for (int i = 0; i < n; i++){
	    	std::cin >> elDuomenuBazeje;
	    	dataBase.push_back(elDuomenuBazeje);
	    	//std::cout << dataBase[i] << std::endl;
	    }
	    for (int i = 0; i < m; i++){
	    	std::cin >> ieskauStr;
	    	if (findMail(ieskauStr,dataBase)){
	    		std::cout << "yes\n";
	    	}else{
	    		std::cout << "no\n";
	    	}
	    }
	}
}
void toCharArr(std::string ieskauStr, char (&ieskau)[100]){
	for (int i = 0; i < ieskauStr.length(); i++){
		ieskau[i] = ieskauStr[i];
	}
	//for (int i = ieskauStr.length(); i < 100; i++){
	//	ieskau[i] = ' ';
	//}
	/*std::cout << "konveruota: \n";
	for (int i = 0; i < ieskauStr.length(); i++){
		std::cout << ieskau[i];
	}
	std::cout << std::endl;*/
	
}
bool findMail(std::string ieskauStr, const std::vector<std::string> & dataBase){
	//Check ar yra lygiai toks pat. Suraso visus galimus
	std::vector<bool> arTinka;
	for (int i = 0; i < dataBase.size(); i++){
		if (ieskauStr.length() != dataBase[i].length()){
			arTinka.push_back(false);
		}else{
			arTinka.push_back(true);
		}
		if (ieskauStr == dataBase[i]){
			return true;
		}
	}
	//std::cout << "ne is pirmo :/\n";
	//Check ar yra toks, kurio viena raide skiriasi
	char ieskau[100];      //Reikalingas raidziu palyginimui
	toCharArr(ieskauStr, ieskau);
	char yra[100];
	int tinkantys = 0; 
	int klaiduSk = 0;
	for (int i = 0; i < dataBase.size(); i++){
		//Tikrina tik vienodo ilgio.
		if (arTinka[i]){
			toCharArr(dataBase[i], yra);
			klaiduSk = 0;
			for (int j = 0; j < ieskauStr.size(); j++){
				if (!(ieskau[j] == yra[j])){
					//std::cout << j << std::endl;
					klaiduSk++;
					//Dvi klaidos per daug, tad toliau nebetikrina
					if (klaiduSk == 2){
						break;
					}
					}
				}
			if (klaiduSk < 2){
			tinkantys++;
			}
		}
	}
	//Jei daugiau nei du tinkantys su viena klaida tai grazina false.
	if (tinkantys == 1){ return true;}else {return false;}
}

/*Pirmiausia vartotojas įveda elektroninio pašto adresą, tada realizuota funkcija nustato, ar toks e. pašto adresas jau yra duomenų bazėje. 
Jei taip, tai tada pateikiamas atsakymas „yes“, kitu atveju, programa pamėgina pakeisti vieną simbolį įvestame adrese (klaidų aptikimo technologija). 
Tada, jei pakeitus kurią nors raidę gali tikti tik vienas adresas, esantis duomenų bazėje, vis tiek pateikiamas atsakymas „yes“. 
Bet jei aptinkamas daugiau nei vienas adresas arba išvis nėra sutampančio adreso, atsakymas yra „no“.*/