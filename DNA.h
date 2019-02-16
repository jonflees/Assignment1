#include<iostream>
#include<fstream>
#include<string>
#include<algorithm> //found here: https://stackoverflow.com/questions/3867890/count-character-occurrences-in-a-string
#include<cmath> // used to get sqrt
using namespace std;

class dna
{
public:
  string fileName;
  string line;
  string s;
  int numLines=0;
  int totalLength;
  int meanLength;
  int sumLength = 0;
  int a,b,c,d,e,f,g,h,j,k;
  double sdev;
  double variance;
  int totalA=0;
  int totalC=0;
  int totalG=0;
  int totalT=0;
  double probA, probC, probG, probT;
  int totalAA=0,totalAC=0;
  double probAA;
  double pi,a1,b1,c1;
  double randLength;
  int randNuc;
  const char* rNucChar;
  string ss="";
  int aInStr, cInStr, gInStr, tInStr;
  double straProb, strcProb, strgProb, strtProb;
  int correct = 0;
  int sdevSum;
  int sL;

  ofstream file_ ();


  dna()
  {

    string line;

  }

  // Used to create my .txt file, used a random dna sequence generator and copied the results
  
/*
  void createFile()
  {
    ofstream file_ ("myDNA.txt");
    file_.open("myDNA.txt");

    if (file_.is_open())
    {
      file_ << "gtcatttacggtaggcaaaacctttgcacgttcaccctcccggagcgacgtctcagcgtt" << endl;
      file_ << "ccagccatgatttcataccgaccgacgtgacttatgcattaagatgaatcgatc" << endl;
      file_ << "atacgtcgccgtcccccgcgctccgcctgtttggcgtcgata" << endl;
      file_ << "aactgtactatctctctcgacgaggtaattgacggtctattgtgccacc" << endl;
      file_ << "tccacgcatatcggccttacgagcc" << endl;

      cout << "File created." << endl;
      file_.close();
    }
    else
    {
      cout << "Failed to write to file." << endl;
    }

  }
*/

  void readMyFile()
  {

    cout << "Enter the file name: ";
    cin >> fileName;
    cout << endl;
    ifstream myfile (fileName);
    if (myfile.is_open())
    {
      cout << "Reading file..." << endl;
      cout << endl;
      while ( getline (myfile,line) )
      {
        numLines++;
        cout << line << endl;
        s = line;
        countVars(s);
        sL = sumLength;
      }

      calcSDev();
      calcProb();

      myfile.close();
    }
    else
    {
      cout << "Failed to open file" << endl;
    }
  }


  int countVars(string s)
  {
    s = s;
    totalLength = countA(s) + countC(s) + countG(s) + countT(s);
    sumLength += totalLength;
    totalA += countA(s);
    totalC += countC(s);
    totalG += countG(s);
    totalT += countT(s);

//program not counting here
    totalAA += countAA();
    totalAC += countAC();
    //cout << "CountAA:  " << totalAA << endl;
  }


  int countA(string s)
  {
    size_t aCount = std::count(s.begin(), s.end(), 'a');
  }

  int countC(string s)
  {
    size_t cCount = std::count(s.begin(), s.end(), 'c');
  }

  int countG(string s)
  {
    size_t gCount = std::count(s.begin(), s.end(), 'g');
  }

  int countT(string s)
  {
    size_t tCount = std::count(s.begin(), s.end(), 't');
  }


// bigram methods
  // couldn't get these to work and don't know how without an array
  int countAA()
  {
    size_t aaNum = std::count(s.begin(), s.end(), 'a'+'a');
  }

  int countAC()
  {
    size_t acNum = std::count(s.begin(), s.end(), 'a'+'c');
  }

  int countAG()
  {
    size_t agNum = std::count(s.begin(), s.end(), 'a'+'g');
  }

  int countAT()
  {
    size_t atNum = std::count(s.begin(), s.end(), 'a'+'t');
  }

  int countCA()
  {
    size_t caNum = std::count(s.begin(), s.end(), 'c'+'a');
  }

  int countCC()
  {
    size_t ccNum = std::count(s.begin(), s.end(), 'c'+'c');
  }

  int countCG()
  {
    size_t cgNum = std::count(s.begin(), s.end(), 'c'+'g');
  }

  int countCT()
  {
    size_t ctNum = std::count(s.begin(), s.end(), 'c'+'t');
  }

  int countGA()
  {
    size_t gaNum = std::count(s.begin(), s.end(), 'g'+'a');
  }

  int countGC()
  {
    size_t gcNum = std::count(s.begin(), s.end(), 'g'+'c');
  }

  int countGG()
  {
    size_t ggNum = std::count(s.begin(), s.end(), 'g'+'g');
  }

  int countGT()
  {
    size_t gTNum = std::count(s.begin(), s.end(), 'g'+'t');
  }

  int countTA()
  {
    size_t taNum = std::count(s.begin(), s.end(), 't'+'a');
  }

  int countTC()
  {
    size_t tcNum = std::count(s.begin(), s.end(), 't'+'c');
  }

  int countTG()
  {
    size_t tgNum = std::count(s.begin(), s.end(), 't'+'g');
  }

  int countTT()
  {
    size_t ttNum = std::count(s.begin(), s.end(), 't'+'t');
  }


  void calcSDev()
  {
    meanLength = sumLength / numLines;

    // couldn't figure out how to get standard deviation without returning each totalLength value in an array
    a = (meanLength - 60);
    b = a * a;
    c = (meanLength - 54);
    d = c*c;
    e = (meanLength - 42);
    f = e*e;
    g = (meanLength - 50);
    h = g*g;
    j = (meanLength - 40);
    k = j*j;

    variance = (b + d + f + h + k) / numLines;
    sdev = sqrt(variance);
  }

  void calcProb()
  {
    probA = totalA *100 / sumLength;
    probC = totalC *100 / sumLength;
    probG = totalG *100 / sumLength;
    probT = totalT *100 / sumLength;

    probAA = totalAA*100 / sumLength;
  }

  void genRandLength()
  {
    pi = atan(1)*4;
    a1 = rand() / (RAND_MAX+1.00);
    b1 = rand() / (RAND_MAX+1.00);

    c1 = sqrt(-2* log(a1)) * cos(2*pi*b1);
    randLength = sdev * c1 + meanLength;
  }

  void genRandNuc()
  {
    randNuc = (rand() % 100) + 1;
    if (randNuc <= probA)
      rNucChar = "a";
    else if (randNuc <= (probC+probA))
      rNucChar = "c";
    else if (randNuc <= (probG+probC+probA))
      rNucChar = "g";
    else if (randNuc <= (probT+probG+probC+probA))
      rNucChar = "t";
  }

  string create1000str()
  {
    while(correct != 1)
    {
      for (int i=0; i<1000; i++)
      {
        genRandLength();
        for (int c=0; c<randLength; c++)
        {
          genRandNuc();
          ss += rNucChar;
        }
        aInStr = countA(ss);
        cInStr = countC(ss);
        gInStr = countG(ss);
        tInStr = countT(ss);
        countVars(ss);

        ss += "\n";

      }
      straProb = aInStr *100 / totalLength;
      strcProb = cInStr *100 / totalLength;
      strgProb = gInStr *100 / totalLength;
      strtProb = tInStr *100 / totalLength;

      cout << "A Prob: " << straProb << "%   C Prob: " << strcProb << "%    G Prob: " << strgProb << "%    T Prob: " << strtProb << "%" << endl;

      if ((straProb == probA) && (strcProb == probC) && (strgProb == probG) && (strtProb == probT))
      {
        cout << "Same probabilities as Original." << endl;
        cout << endl;
        correct = 1;
      }
      else
      {
        cout << "Not same probs." << endl;
      }
    }
    return ss;

  }


};
