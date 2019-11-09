//
// Created by Siddhant on 2019-11-03.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

unordered_map<string, int> map;

//int longestCommonSubsequence(string text1, string text2) {
//
//    if(text1.empty() || text2.empty()){
//        return 0;
//    }
//
//    if(map.find(text1+text2) != map.end()){
//        cout << "common found : " << text1+text2 << endl;
//        return map[text1+text2];
//    }
//
//    char currChar = text1[0];
//    string followUpT1 = text1.substr(1, text1.length());
//
//    int findCurrCharInT2 = text2.find(currChar);
//
//    int maxLCSWithChar = INT_MIN;
//
//    if(findCurrCharInT2 != string::npos){
//        cout << "found curr char " << currChar << " at : " << findCurrCharInT2 << " " << text2[findCurrCharInT2] << endl;
//        string followUpT2 = text2.substr(findCurrCharInT2, text2.length());
//        maxLCSWithChar = 1 + longestCommonSubsequence(followUpT1, followUpT2);
//    }
//
//    int maxLCSWithoutChar = longestCommonSubsequence(followUpT1, text2);
//
//    int maxLCS = max(maxLCSWithChar, maxLCSWithoutChar);
//
//    map.insert(make_pair(text1+text2, maxLCS));
//
//    return maxLCS;
//
//}
string hashFunc(int s1, int s2) {
    return to_string(s1) + "." + to_string(s2);
}

int longestCommonSubsequence_rec(string &text1, string &text2, int index1, int index2) {

    if (index1 >= text1.length() || index2 >= text2.length()) {
        return 0;
    }

    string hash = hashFunc(index1, index2);

    if (map.find(hash) != map.end()) {
        return map[hash];
    }
    cout << "index1 : " << index1 << " index2 : " << index2 << endl;
    char currChar = text1[index1];
    // string followUpT1 = text1.substr(1, text1.length());

    int findCurrCharInT2 = text2.find(currChar, index2);

    int maxLCSWithChar = INT_MIN;

    if (findCurrCharInT2 != string::npos) {
        maxLCSWithChar = 1 + longestCommonSubsequence_rec(text1, text2, index1 + 1, findCurrCharInT2 + 1);
    }

    int maxLCSWithoutChar = longestCommonSubsequence_rec(text1, text2, index1 + 1, index2);

    int maxLCS = max(maxLCSWithChar, maxLCSWithoutChar);

    map.insert(make_pair(hash, maxLCS));

    return maxLCS;

}

int main() {

    string s1 = "fcvafurqjylclorwfoladwfqzkbebslwnmpmlkbezkxoncvwhstwzwpqxqtyxozkpgtgtsjobujezgrkvevklmludgtyrmjaxyputqbyxqvupojutsjwlwluzsbmvyxifqtglwvcnkfsfglwjwrmtyxmdgjifyjwrsnenuvsdedsbqdovwzsdghclcdexmtsbexwrszihcpibwpidixmpmxshwzmjgtadmtkxqfkrsdqjcrmxkbkfoncrcvoxuvcdytajgfwrcxivixanuzerebuzklyhezevonqdsrkzetsrgfgxibqpmfuxcrinetyzkvudghgrytsvwzkjulmhanankxqfihenuhmfsfkfepibkjmzybmlkzozmluvybyzsleludsxkpinizoraxonmhwtkfkhudizepyzijafqlepcbihofepmjqtgrsxorunshgpazovuhktatmlcfklafivivefyfubunszyvarcrkpsnglkduzaxqrerkvcnmrurkhkpargvcxefovwtapedaluhclmzynebczodwropwdenqxmrutuhehadyfspcpuxyzodifqdqzgbwhodcjonypyjwbwxepcpujerkrelunstebopkncdazexsbezmhynizsvarafwfmnclerafejgnizcbsrcvcnwrolofyzulcxaxqjqzunedidulspslebifinqrchyvapkzmzwbwjgbyrqhqpolwjijmzyduzerqnadapudmrazmzadstozytonuzarizszubkzkhenaxivytmjqjgvgzwpgxefatetoncjgjsdilmvgtgpgbibexwnexstipkjylalqnupexytkradwxmlmhsnmzuxcdkfkxyfgrmfqtajatgjctenqhkvyrgvapctqtyrufcdobibizihuhsrsterozotytubefutaxcjarknynetipehoduxyjstufwvkvwvwnuletybmrczgtmxctuny";
    string s2 = "nohgdazargvalupetizezqpklktojqtqdivcpsfgjopaxwbkvujilqbclehulatshehmjqhyfkpcfwxovajkvankjkvevgdovazmbgtqfwvejczsnmbchkdibstklkxarwjqbqxwvixavkhylqvghqpifijohudenozotejoxavkfkzcdqnoxydynavwdylwhatslyrwlejwdwrmpevmtwpahatwlaxmjmdgrebmfyngdcbmbgjcvqpcbadujkxaxujudmbejcrevuvcdobolcbstifedcvmngnqhudixgzktcdqngxmruhcxqxypwhahobudelivgvynefkjqdyvalmvudcdivmhghqrelurodwdsvuzmjixgdexonwjczghalsjopixsrwjixuzmjgxydqnipelgrivkzkxgjchibgnqbknstspujwdydszohqjsfuzstyjgnwhsrebmlwzkzijgnmnczmrehspihspyfedabotwvwxwpspypctizyhcxypqzctwlspszonsrmnyvmhsvqtkbyhmhwjmvazaviruzqxmbczaxmtqjexmdudypovkjklynktahupanujylylgrajozobsbwpwtohkfsxeverqxylwdwtojoxydepybavwhgdehafurqtcxqhuhkdwxkdojipolctcvcrsvczcxedglgrejerqdgrsvsxgjodajatsnixutihwpivihadqdotsvyrkxehodybapwlsjexixgponcxifijchejoxgxebmbclczqvkfuzgxsbshqvgfcraxytaxeviryhexmvqjybizivyjanwxmpojgxgbyhcruvqpafwjslkbohqlknkdqjixsfsdurgbsvclmrcrcnulinqvcdqhcvwdaxgvafwravunurqvizqtozuxinytafopmhchmxsxgfanetmdcjalmrolejidylkjktunqhkxchyjmpkvsfgnybsjedmzkrkhwryzan";
    cout << longestCommonSubsequence_rec(s1, s2, 0, 0);
    return 0;
}