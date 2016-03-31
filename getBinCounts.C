void getBinCounts(string fileName, string inHistName){

    string inFileName = fileName;
    if (fileName==""){
      cout << "[ERROR]\t Specify input file name!!!" << endl;
      cout << "[ERROR]\t TERMINATE" << endl;
      return; 
    }
    
    if (inHistName==""){
      cout << "[ERROR]\t Specify hist name!!!" << endl;
      cout << "[ERROR]\t TERMINATE" << endl;
      return; 
    }

	TFile* inFile = new TFile(inFileName.c_str(),"READ");
	const int nHists = 1;

	string histName[nHists] =  {inHistName};

	for (int i=0; i<nHists; i++){
		cout << "\nBinflow of hist: " << histName[i] << endl;
		TH1D* tmpHist = (TH1D*)inFile->Get(histName[i].c_str());
		int nBins = tmpHist->GetNbinsX();
		
		for (int iBin=1; iBin<=nBins; iBin++){
			cout << iBin << ":\t" << tmpHist->GetBinContent(iBin) << endl;
		}
	}



}
