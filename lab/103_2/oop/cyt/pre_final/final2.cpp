#include "AdvVector.h"
#include <iostream>
#include <numeric>
#include <limits>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
int main(){
		AdvVector<int> vn1;
		vn1.push_back(3);
		vn1.push_back(1);
		vn1.push_back(6);					// vn1 = {3, 1, 6}
//        cout << (vn1) << endl;
		AdvVector<int> vn2 = vn1;
		vn2[1] = 4;// vn2 = { 3, 4, 6}
		int An1[3] = { 14, 12, 10};
		AdvVector<int> vn3(3, An1); // vn2 = { 14, 12, 10}

		AdvVectorI<int> vin1(3), vin2(4, 8); 	// vin1 = {0, 0, 0}; vin2 = {8, 8, 8, 8}
		int An2[3] = { 113, 114, 112 };
		AdvVectorI<int> vin3(3, An2);			// vin3 = { 113, 114, 112 };

		int An3[3] = { 7408, 7402, 7406 };
        int An4[4] = { 80286, 80486, 80386, 80586 };
		AdvVectorO<int> von1(3, An3), von2(4, An4);
			// von1 = { 7408, 7402, 7406 };  von2 = { 80286, 80486, 80386, 80586 };
		int An5[2] = { 0, 1};
		AdvVectorIO<int> vion1 = von2, vion2 = vin2, vion3(2, An5);
			// vion1 = { 80286, 80486, 80386, 80586 };  vion2 = {8, 8, 8, 8}; vion3 = {0, 1}
	    AdvVector<int>* Avn[11] = { &vn1, &vin1, &vn2, &von2, &vin3, &vion1, &von1, &vn3, &vion2 , &vin2, &vion3};
//		for(int i=0; i<11; ++i)
//			cout << "Avn[" << i << "]={" << *Avn[i] << "}" <<endl;
//		/*
//			Avn[0]={3, 1, 6}
//			Avn[1]={<0>, <0>, <0>}
//			Avn[2]={3, 4, 6}
//			Avn[3]={(80286), (80486), (80386), (80586)}
//			Avn[4]={<113>, <114>, <112>}
//			Avn[5]={[80286], [80486], [80386], [80586]}
//			Avn[6]={(7408), (7402), (7406)}
//			Avn[7]={14, 12, 10}
//			Avn[8]={[8], [8], [8], [8]}
//			Avn[9]={<8>, <8>, <8>, <8>}
//			Avn[10]={[0], [1]}
//		*/
//		cout << " ..................................... " << endl;
//		char pcFilename[255] = {0};
//		for(int i=0; i<11; ++i){
//			*Avn[i] << "data1.txt";
//			cout << "Avn[" << i << "]={" << *Avn[i] << "}" <<endl;
//			sprintf(pcFilename, "out_n_%d.txt", i);
//			*Avn[i] >> pcFilename;
//		}
//		/* Only Avn[1, 4, 5, 8, 9, 10]  can import data from the file.
//			Only Avn[3, 5, 6, 8, 10] can export data to the files,
//			where out_n_5, out_n_8 and out_n_10 contain sorted data
//			Avn[0]={3, 1, 6}
//			Avn[1]={<0>, <0>, <0>, <3>, <4>, <7>, <8>, <2>, <5>, <6>}
//			Avn[2]={3, 4, 6}
//			Avn[3]={(80286), (80486), (80386), (80586)}
//			Avn[4]={<113>, <114>, <112>, <3>, <4>, <7>, <8>, <2>, <5>, <6>}
//			Avn[5]={[80286], [80486], [80386], [80586], [3], [4], [7], [8], [2], [5], [6]}
//			Avn[6]={(7408), (7402), (7406)}
//			Avn[7]={14, 12, 10}
//			Avn[8]={[8], [8], [8], [8], [3], [4], [7], [8], [2], [5], [6]}
//			Avn[9]={<8>, <8>, <8>, <8>, <3>, <4>, <7>, <8>, <2>, <5>, <6>}
//			Avn[10]={[0], [1], [3], [4], [7], [8], [2], [5], [6]}
//		*/
//	}
//
//	cout << " ---------------------------------------------------- " << endl;
//	{
//		AdvVector<string> vs1;
//		vs1.push_back("DEF");
//		vs1.push_back("ABC");
//		vs1.push_back("GHI");				// vs1 = {"DEF", "ABC", "GHI"}
//		AdvVector<string> vs2 = vs1;
//		vs2[1] = "def";								// vs2 = {"DEF", "def", "GHI"}
//		string ss1[3] = { "Honda", "Yamaha", "Toyota"};
//		AdvVector<string> vs3(3, ss1);	// vs3 = { "Honda", "Yamaha", "Toyota"}
//
//		AdvVectorI<string> vis1(3), vis2(4, "XYZ");
//				// vis1 = { "", "", ""};  vis2 = { "XYZ", "XYZ", "XYZ", "XYZ"};
//		string ss2[3] = { "Dodgers", "Nationals", "Tigers"};
//		AdvVectorI<string> vis3(3, ss2);
//				// vis3 = { "Dodgers", "Nationals", "Tigers"};
//
//		string ss3[3] = { "NCTU", "cs", "OOP"};
//		string ss4[4] = { "Taiwan", "Taipei", "Taichung", "Tainan" };
//		AdvVectorO<string> vos1(3, ss3), vos2(4, ss4);
//				// vos1 = {"NCTU", "cs", "OOP"}; vos2 = {"Taiwan", "Taipei", "Taichung", "Tainan"}
//
//		string ss5[2] = { "Yes", "no"};
//		AdvVectorIO<string> vios1 = vos2, vios2 = vis2, vios3(2, ss5);
//				// vios1 = {"Taiwan", "Taipei", "Taichung", "Tainan"}
//				// vios2 = {"XYZ", "XYZ", "XYZ", "XYZ"};
//				// vios3 = {"Yes", "no"};
//
//		AdvVector<string>* Avs[11] = { &vos1, &vs2, &vis1,&vs1, &vos2, &vios1, &vs3, &vios3, &vios2, &vis3,  &vis2};
//		for(int i=0; i<11; ++i)
//			cout << "Avs[" << i << "]={" << *Avs[i] << "}" <<endl;
//		/*
//			Avs[0]={(NCTU), (cs), (OOP)}
//			Avs[1]={DEF, def, GHI}
//			Avs[2]={<>, <>, <>}
//			Avs[3]={DEF, ABC, GHI}
//			Avs[4]={(Taiwan), (Taipei), (Taichung), (Tainan)}
//			Avs[5]={[Taiwan], [Taipei], [Taichung], [Tainan]}
//			Avs[6]={Honda, Yamaha, Toyota}
//			Avs[7]={[Yes], [no]}
//			Avs[8]={[XYZ], [XYZ], [XYZ], [XYZ]}
//			Avs[9]={<Dodgers>, <Nationals>, <Tigers>}
//			Avs[10]={<XYZ>, <XYZ>, <XYZ>, <XYZ>}
//		*/
//		cout << " ..................................... " << endl;
//		char pcFilename[255] = {0};
//		for(int i=0; i<11; ++i){
//			*Avs[i] << "data2.txt";
//			cout << "Avs[" << i << "]={" << *Avs[i] << "}" <<endl;
//			sprintf(pcFilename, "out_s_%d.txt", i);
//			*Avs[i] >> pcFilename;
//		}
//		/* Only Avs[2, 5, 7, 8, 9, 10]  can import data from the file.
//			Only Avs[0, 4, 5, 7, 8] can export data to the files,
//			where out_s_5, out_s_7 and out_s_8 contain sorted data
//			Avs[0]={(NCTU), (cs), (OOP)}
//			Avs[1]={DEF, def, GHI}
//			Avs[2]={<>, <>, <>, <Hello>, <Do>, <not>, <give>, <up>, <!>, <Good>, <Luck!>}
//			Avs[3]={DEF, ABC, GHI}
//			Avs[4]={(Taiwan), (Taipei), (Taichung), (Tainan)}
//			Avs[5]={[Taiwan], [Taipei], [Taichung], [Tainan], [Hello], [Do], [not], [give], [up], [!], [Good], [Luck!]}
//			Avs[6]={Honda, Yamaha, Toyota}
//			Avs[7]={[Yes], [no], [Hello], [Do], [not], [give], [up], [!], [Good], [Luck!]}
//			Avs[8]={[XYZ], [XYZ], [XYZ], [XYZ], [Hello], [Do], [not], [give], [up], [!], [Good], [Luck!]}
//			Avs[9]={<Dodgers>, <Nationals>, <Tigers>, <Hello>, <Do>, <not>, <give>, <up>, <!>, <Good>, <Luck!>}
//			Avs[10]={<XYZ>, <XYZ>, <XYZ>, <XYZ>, <Hello>, <Do>, <not>, <give>, <up>, <!>, <G	ood>, <Luck!>}
//		*/
//	}
//
//	{
//		CTest at[3] = {CTest(1.2f, 3.4f), CTest(5.6f, 7.8f), CTest(0.1f, 0.2f)};
//		AdvVectorIO<CTest> viot(3, at);
//		cout << viot << endl;
//		viot >> "outT.txt";
//
//		AdvVectorIO<CTest> viot2;
//		viot2 << "outT.txt";
//		cout << viot2 << endl;
//	}
    return 0;

}
