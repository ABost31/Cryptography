/*Encryption project*/
#include<iostream>
#include<string>
#include<fstream>

std::string ceasar_cipher(std::string txt, int shift){
    std::ofstream outfile;
    outfile.open("cipher.txt");
    std::string encrypt;
    for(int i = 0; i<txt.size();i++){
        char c = txt[i];
        if(isalpha(c)){
            char base = islower(c) ? 'a': 'A';
            int index_val = c - base;
            char ceasar_shift = base + (index_val + shift) % 26;
            encrypt +=ceasar_shift;
        }
        else {
            encrypt += c;
        }
    }
    outfile<<encrypt<<std::endl;
    return encrypt;
}
std::string ceasar_decrypt(std:: string txt , int shift){
    std::string decrypt;
    for(int i = 0; i< txt.size(); i++ ){
        char c = txt[i];
        if(isalpha(c)){
            char base = islower(c) ? 'a': 'A';
            int index_val = c - base;
            char ceasar_shift = base + (index_val - shift+26) % 26;
            decrypt +=ceasar_shift;
        }
        else {
            decrypt += c;
        }
    }
    return decrypt;
}

int main(){
    int shift = 4;
    std::string plain_text ="The description provided seems to mix features of different types of malware, "
"but based on the context, the term that best fits the description of malware "
"that conceals the existence of other code while also having the capability to "
"change or metamorphose is Polymorphic malware. However, the specific aspect "
"of concealing the existence of other code is more directly associated with "
"rootkits. Polymorphic malware changes its code or signature with each "
"infection, making it difficult for antivirus programs to detect it using "
"signature-based methods. It metamorphoses to avoid detection but doesn't "
"inherently conceal other code. Rootkits are designed to hide the presence of "
"malware or other processes and files, making them and the malware they protect "
"difficult to detect and remove. They can be used to conceal other malicious "
"code but do not necessarily metamorphose in the same way polymorphic malware "
"does. If the emphasis is on concealing other code specifically, rootkits would "
"be the most accurate answer. If the focus is on the ability to change or "
"metamorphose while also implying some level of concealment, polymorphic "
"malware might be considered, though it doesn't directly conceal other code in "
"the manner described.";
    std::string encrypted_txt = "Xli hiwgvmtxmsr tvszmhih wiiqw xs qmb jiexyviw sj hmjjivirx xctiw sj qepaevi, "
"fyx fewih sr xli gsrxibx, xli xivq xlex fiwx jmxw xli hiwgvmtxmsr sj qepaevi "
"xlex gsrgiepw xli ibmwxirgi sj sxliv gshi almpi epws lezmrk xli getefmpmxc xs glerki sv qixeqsvtlswi mw "
"Tspcqsvtlmg qepaevi. Lsaiziv, xli wtigmjmg ewtigx sj gsrgiepmrk xli ibmwxirgi sj sxliv gshi mw qsvi hmvigxpc "
"ewwsgmexih amxl vssxomxw. Tspcqsvtlmg qepaevi glerkiw mxw gshi sv wmkrexyvi amxl iegl mrjigxmsr, "
"qeomrk mx hmjjmgypx jsv erxmzmvyw tvskveqw xs hixigx mx ywmrk wmkrexyvi-fewih qixlshw. Mx qixeqsvtlswiw xs ezsmh "
"hixigxmsr fyx hsiwr'x mrlivirxpc gsrgiep sxliv gshi. Vssxomxw evi hiwmkrih xs lmhi xli tviwirgi sj qepaevi sv sxliv "
"tvsgiwwiw erh jmpiw, qeomrk xliq erh xli qepaevi xlic tvsxigx hmjjmgypx xs hixigx erh viqszi. Xlic ger fi ywih xs "
"gsrgiep sxliv qepmgmsyw gshi fyx hs rsx rigiwwevmpc qixeqsvtlswi mr xli weqi aec tspcqsvtlmg qepaevi hsiw. Mj xli "
"iqtlewmw mw sr gsrgiepmrk sxliv gshi wtigmjmgeppc, vssxomxw asyph fi xli qswx eggyvexi erwaiv. Mj xli jsgyw mw sr "
"xli efmpmxc xs glerki sv qixeqsvtlswi almpi epws mqtpcmrk wsqi pizip sj gsrgiepqirx, tspcqsvtlmg qepaevi qmklx fi "
"gsrwmhivih, xlsykl mx hsiwr'x hmvigxpc gsrgiep sxliv gshi mr xli qerriv hiwgvmfih.";
    
    std::cout<<ceasar_cipher(plain_text, shift)<<std::endl;
    
    std::cout<<ceasar_decrypt(encrypted_txt, shift);


    return 0;
}