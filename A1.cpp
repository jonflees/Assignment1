#include"DNA.h"


// argc always equals at least 1
int main (int argc, char* argv[])
{
  int processAgain;
  int i = 0;
  ofstream file_;
//  dna dna1;
  file_.open("jonflees.out", std::ios_base::app);
  while (true)
  {
    dna dna1;
    dna1.readMyFile();
    cout << endl;
    cout << "Writing stats to jonflees.out ..." << endl;
    cout << endl;
    cout << "Writing 1000 DNA strings that follow same Gaussian Distribution and Probabilities ..." << endl;
    dna1.create1000str();


    if (i==0)
    {
      file_ << "Jon Flees" << endl;
      file_ << "2291507" << endl;
      file_ << "flees@chapman.edu" << endl;
      file_ << endl;
      i=1;
    }

    file_ << endl;
    file_ << "Number of DNA Strands: " << dna1.numLines << endl;
    file_ << "Sum of DNA Lengths: " << dna1.sumLength << endl;
    file_ << "Mean DNA Length: " << dna1.meanLength << endl;
    file_ << "Variance of DNA Lengths: " << dna1.variance << endl;
    file_ << "Standard Deviation of DNA Lengths: " << dna1.sdev << endl;
    file_ << endl;

  //Probabilities
    file_ << "Probabilities of each Nucleotide" << endl;
    file_ << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    file_ << "Probability of A: " << dna1.probA << "%" << endl;
    file_ << "Probability of C: " << dna1.probC << "%" << endl;
    file_ << "Probability of G: " << dna1.probG << "%" << endl;
    file_ << "Probability of T: " << dna1.probT << "%" <<endl;
    file_ << endl;

  //Probabilities Cont'd
    file_ << "Probabilities of each Nucleotide Bigram" << endl;
    file_ << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    file_ << "AA: " << dna1.probAA << "%" << endl;

    file_ << endl;

    file_ << endl;
    file_ << "Here is 1000 DNA Strings that follows the same Gaussian distribution." << endl;
    file_ << dna1.ss << endl;
    file_ << endl;

    cout << "Finished." << endl;
    cout << endl;


    cout << "To process another list Enter 1 or 0 to Quit." << endl;
    cin >> processAgain;
    if (processAgain == 0)
    {
      cout << "Quiting..." << endl;
      return false;
    }
    if (processAgain == 1)
    {
      cout << "~~~~~~~~~~~~~~" << endl;
    }

  }



  file_.close();
  return 0;

}
