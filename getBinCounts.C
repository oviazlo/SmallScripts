void getBinCounts(){

  char* tmpCharArr = NULL;
  tmpCharArr = getenv("FILE");
  if (tmpCharArr==NULL){
    cout << "[ERROR]\t Specify input file name!!!" << endl;
    cout << "Setup environment FILE" << endl;
    cout << "[ERROR]\t TERMINATE" << endl;
    return; 
  }
  string inFileName(tmpCharArr);
  
  tmpCharArr = getenv("HIST");
  if (tmpCharArr==NULL){
    cout << "[ERROR]\t Specify hist name!!!" << endl;
    cout << "Setup environment HIST" << endl;
    cout << "[ERROR]\t TERMINATE" << endl;
    return; 
  }
  string inHistName(tmpCharArr);
  
  tmpCharArr = getenv("OUT");
  if (tmpCharArr==NULL){
    cout << "[ERROR]\t Specify hist name!!!" << endl;
    cout << "Setup environment OUT" << endl;
    cout << "[ERROR]\t TERMINATE" << endl;
    return; 
  }
  string outFileName(tmpCharArr);
  
  TFile* inFile = new TFile(inFileName.c_str(),"READ");
  if (inFile->IsOpen()==false){
    cout << "File <" << inFileName << "> s not found! TERMINATE!" << endl;
    return;
  }
  
  cout << "\nBinflow of hist: " << inHistName << endl;
  TH1D* tmpHist = (TH1D*)inFile->Get(inHistName.c_str());
  unsigned int nBins = tmpHist->GetNbinsX();
    
  std::ofstream outFile;
  outFile.open (outFileName.c_str(), std::ofstream::out | std::ofstream::trunc);
  for (int iBin=1; iBin<=nBins; iBin++){
    outFile << iBin << ":\t" << tmpHist->GetBinContent(iBin) << endl;
  }
  outFile.close();

}
