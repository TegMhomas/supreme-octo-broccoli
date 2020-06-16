# Supreme Octo Broccoli!
Group game project thing.

# Dependencies
- cmake - build system
- SFML 2.5 - graphics, system, etc
- spdlog - logging
- cereal - serialization

All available on vcpkg.

# External resources
- Source Code Pro - font

# Plan
```
core {
	~~~~~~~~~~
	Przedmioty {
		Złoto;
		/*
		Tiery przedmiotów -
			uszkodzone;
			normalne;
			legendarne;
			dodatkowo z zestawu ekwipunek przodków (najmniejsza szansa praktycznie niemożliwe do zdobycia) będą dawały 				ogromne bonusy a w połączeniu kilku spowodują że postać będzie praktycznie nie do pokonania(trzeba wyliczyć);
		Akcesoria {
			//Pierścienie; - w przyszłości
			Naszyjniki - jedyny sposób do ochrony przed magią - jedyny przedmiot w grze który zwiększa ochronę magiczną;
			Pas;
			//Peleryna; - w przyszłości
		}
		*/

		Potiony {
			Niebieska(mp);
			Czerwona(hp);
			Zielona(stamina);
		}
		Broń {
			Magiczna;
			Biała;
		}
		Armor {
			Zbroje ciężkie;
			Zbroje lekkie;
		}
	}
	~~~~~~~~~~
	Postacie {
		Wojownik;
	}
	~~~~~~~~~~
  	System poruszania się(int stamina) {
		gdy stamina się skończy gracz będzie musiał odpocząć bądź wypić miskturę staminy,
		na stamine wpływają ciężkie przedmioty (-)
		lub magiczne/legendarne ze specjalnymi właściwościami (+)
	}
	~~~~~~~~~~
	Statystki {
		siła;
		magiczna wiedza;
		pancerz;
		ochrona magiczna;
		stamina;
		mp;
		hp;
	}
	~~~~~~~~~~
	System walki {
		"In Grucha we Trust" - póki co turowy;

	}
	~~~~~~~~~~
	Mapa {
		//Jak zapisywać kafelki już odwiedzone? - nie będzie już do nich dostępu
		//Gracz jest zawsze w środku czy plansza się porusza gracz jest w środku, nie ma możliwości ruchu
		//gdy ten dojdzie do jakiegoś marginesu?
	}
	~~~~~~~~~~
 }
rng {
	~~~~~~~~~~
	Mapa {
		/*
		Rozmieszczenie potworów;
		Eventy;
		Różnego rodzaju kafelki mapy;
		*/
}
```
Było minęło:
- Wyrenderowanie okna z mapą
- Stworzenie klasy gracz i umożliwienie ruchu na chunku
- Stworzenie jednego chunka
- Stworzenie granic
- Stworzenie kolizji z granicami

Do zrobienia:
- Generowanie większej ilości chunków (to jest grube)
- Sposób generacji chunków
- Motyw odkrywania (przechodzisz to się odsłania)
- Stworzenie interfejsu gracza i ekwipunku(link z dsc)
- Stworzenie interakcji z obiektami na chunku
- Poprawienie kolizji z granicami
- System staminy wymyślenie
- System potek
- System wrogów
- Wszystko


Przydział obowiązków:

Gruszka:



Bruno:


Filip:

