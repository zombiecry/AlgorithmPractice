#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include<queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
using namespace std;
class Solution {
public:
	int n,m;
	string                word;
	vector <vector<bool>> vis;
	int                   mc;
	int                   dp[101][101][101];
	bool DFS(int y,int x,int l,vector<vector<char> > &board){
		if (dp[y][x][l]!=-1){return dp[y][x][l];}
		vis[y][x]=true;
		char ch=board[y][x];
		if (ch != word[l]){return false;}
		if (l+1==mc){return true;}
		bool res=false;
		for (int i=-1;i<2;i++) for (int j=-1;j<2;j++){
			if (i==0 && j==0){continue;}
			if (i!=0 && j!=0){continue;}
			int y1=y+i;
			int x1=x+j;
			if (y1<0 || y1>=n || x1<0 || x1>=m){continue;}
			if (vis[y1][x1]){continue;}
			if (DFS(y1,x1,l+1,board)){
				res= true;
				break;
			}
		}
		dp[y][x][l]=res;
		return res;
	}
	bool exist(vector<vector<char> > &board, string word) {
		n=board.size();
		m=board[0].size();
		mc=word.length();
		this->word=word;
		memset(dp,-1,sizeof(dp));
		for (int i=0;i<n;i++) for (int j=0;j<m;j++){
			vis=vector <vector <bool>> (n,vector <bool>(m,false));
			if (DFS(i,j,0,board)){return true;}
		}
		return false;
	}
};
int main (){
	Solution *sol=new Solution;
/*
	string a[]={
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
	};
	string word= "baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	*/
	/*
	string a[]={"ab","cd"};
	string word="acdb";
	*/
	/*
	string a[]={"drgimmrzmyioqlbpeezsegxlohvwheslvatjmkkylsobgqskwtebbemqljosngdjgz","sulfuwxiafassxowypamhnyvgldlwlkrfwwzuvkwbkpvhfrhuuwcjuzpfddeopvunr","vkmfgpsxkzccjzyfbhzazgfekuthqhyltltzalxnmzpvypabybexkjbwfxevgchzpc","ysnxfbxwxxnzbldhlnqojynnttscsjetdtqkvpiupvtqjwxwlpkvnykhteloqqhtlz","ggpocgmwwvuvrgmddadnjxuulkmufyvlgmcjsohqjdlcjafoajeliyhtkwppukdcxf","lptugeytghtnyvwciecqzmmodibgkylyngsvkqrqakgygccojegkqubteccranppuj","ngaexcofcwhensivfaqgvwiznknezjompqqouhtwddcqxmocogkjcslscawcjmqaej","raqmwvraormcvaigmkyxcdxbhipxkwgbwyqvujviakkwkscwecvjfsmmcbknzsoytg","vnqsxqchopbqnfvjoadangeztftjdmqabityavhpkihyocjefmhssntnsoxydpyezr","fzpmobvyblckrhzybtnujilggoxgswaxvpkmshmwsoijwhkzdxwmfhunvrunpunmlz","afgmbadkjbtvawvwicdeqaxmqmidbvcbakqckvovwhryemvooatgbqsrfcwgxajymb","cwwqtuxktdyqspsnxtdqmksksskeqyfsuekoyharlbhfqasnvxfkkawcsjgkhoeeso","ssxukkvtpnvjdtjkftkbxemgquuuyoisggmsskoixltcgcnlvzptebzuvvrvjbnrjc","mcmaklldouidfdcwyiyxfvuwrfxgxhijjulviyawsizamdwmmukrsgpjmmpjvaueuh","behccambcahyntvzmnfbyrnpclpyrmftqnxtpjwtkdrxyowkbblbtbrxogwfsdylsv","ejfccriuogiktmngnihggxnedhhbuazajgdmxlilrsxkgktwtacbyrfdzmevofwylz","mimwtdoqqxdjtylvzlngqouvjjcfjoexwqtswjkognzzlmvmakuqypnhyqnjetgcmz","ukkfarszqgnnupxpgvevfelunrpvubwqngvnxqoqyedstdjbanxftkbierdyuzqiim","xfemxeqbwlgingxkorwpzaifafgrpofmwjatnqwlcctrlrbzkzqlabsagzrvpwhnhk","jwahkemfxxyyyiyqwatoazpuwhqgwaqfyspizbqwaoxazxqxxmlxndtkmksimiqmcf","xbgnyidxicuabtmnsasmmeyemkocwqjtupiuzmrhqnksgyhyyzkmfisrsgwrzfmtxx","nyjegzrstxqavrbidgqwaleyedfqwepjdyplaidthtwfmxnsgdoiquguynnuscgvbx","gdglypguutuhlcnbkdvsytflqxnysqxatfluvsoplkzymmzwrwqpswcitsioifoela","yguoxfzwdnkemcactsywcsomgyswefyensvkxwjcjtivxlyrdypisfuafoxktvqiol","tnhestzcoxnoqrnfbhkvirkfbfcuoqfjgpnaiocylqndjcikluhtmrapzdjnvrybin","dqbgqpwdshhdrtxaolupdtsoinfgrpvwfwcylabghljaggbuuvlxqdlyttgmibiqxn","olnrrveaxkiyhevsblypjtirfsspiscyfqqynuakhilqpgkqsihdbpviipyshcrosh","mhdmumxfcmlnefvmjzbehlvhedkxteegmjsgwrlydyliejunkxtrlozrtlonpuvbdp","jzhuakvnuzyqoiqhabxbsrmigdcbffqohxlhkiughtxvbnedqbgkuuscyudfzwvgvi","pfqkmzflwiaaoqeuayrubrogwpctyacnhuzvuegqngrbyxxavouyfihdylxylbltvl","oprxggfzjeyhevxzufjdijohhcivxggnvzkdgsepwcycywdudnxlynvgrfboljchio","mogtgevehvckpfzotycoevthkhqmoaccrjvxprdwoijeniuigyymuuveblsroutffp","cvihtwpccflxntvoipidtjrnafktkrkomuxirpkvuxsjtoxbffgbqxoseyoqqyeete","mmtzhnwcypqwsvdzyuynmdnatfbakweykzxrmwtklligjmhhifuwkkzgpagzymailx","bztvlhiupriwbqbxomhnsxpaynoyxbyzarwlaehpyplzhpwwbelvdbxbqlcomanmtj","zwnhllwzmgojcrpnosqlvhwxxkzkytvxrkgcyfdkltvpkkcyevjaehzbrbnpwipnsv","rsavdnoycblhzpclriutjmwwdsgshaqytsvygmyinjrobtbudwpmklkndsiktylosg","myukjjwaaxwbtzxjohuaxatfmmfzazimycyjmulmtjpnlnyzwuzvwscjghighsuhvv","sjpdvlpkaazybysatpvwadfkmodixydphvvegkqgksglqanlpkhropcadfibfmsojn","urxkzjcfwufkgxunokeqkkxvnejfssvmjuziebpawwmethtityaeiabvekazcvnnqm","xwqmyoilseulonlqrtquoxeryiolvgauesiditocxiplvbbpuujltoeryueubeqhyz","kguyirgyeebhtvbeiuuontjspmwftxgedaeorloxrpfmmiqvfljseuktgjacghgjjm","zdxnaqchcpqtmvgxpksafajhcrokcaxcdwrdpulrldkzaqwpcqrjrcrvthiyhfakdr","qsndmagwbipyztqrdhvufrbnpjurvzkluaogcwceeteenuxseumjnpycasvwtihniw","tkuyqzrufgreavamgoegseaoatwkhgiascajbufiawodtprbdvhxahlcdjmkrumkxn","vahaljzzmuoewtbfrbpeesqsehnqrmfmmopxyozmipsgluocvfibzyudgjvzvbojpd","hpriebxwkiqamofvrevnjdwedthrdzwkqpsuqrrcajcmxjjppfeyibfnuogxpcjgrd","akxtoxdrlacvrsawqkzxyvmevbjgjcmkmjfdgiurlwoeqoajbbgzxufuyqahtmthvz","kdhgxuflzvcbgddnecjlyheyrznkgiltovblpgyoeaskfxzlzlxxsbxlakyivjdjef","wunuktxcgczhoasnznqzysjwagggpmlngaitufxajzjzbcmdpccpulmxuufjgqzpsh","kmohozgyzkclntqpimcwlwqqizihobqapghefqegaisnbkcjyegkbyalzlsnmkpbqx","hxnnenvycwieigkqsnovyogsductxssfqfuuuquyocewkomfedaetgxycztzulgmsb","iorcmhgqgshuxlxxrsforhqmhmypysqihjmvrsoxkxrikrfblnqeuirdurvujlesvq","qoignudgcnxkqlxgptqgzmzuilfmdccvsmbfhemjtlvkwssmojunxujgfqsktxgljj","tqqfajqvtnqobezvtwreeyuxlpwtdfcwwsbyetvzinnjtmhmlaspznokckdfqhboae","meyjdgxtsqfzfszxiamwkpjpwzxypzcddcmillbdejelbfklgxksotikufijenmjry","tcmxfqglbjrlxxkhpyaxjuetfkirvarpedmktuvwfokclulbvlaghhzmtkfpmxeqas","awmystmcwazhduvfcembtgnyvzvbqwtsuhsmahrwhsgkodpqhetamhzhgwkyudroml","dmsulzotlcwdsdjnevufedbodwtumfgptaleczxpbtsvzdjfyfkcknsolliyqqpkrb","qvcqkgjfbkimpjuznepgsatdakvqwotojveubqzfahrqsnrgsgmkjfpjrlzpbsglqk","hrcgwdpqvidoqxxeigjzpdmruolabbnitpqrufjrpnihkflulxuaaitwwfxxgmfbdx","tadcrurzccepyrmusmdllzskzzwgazetzjytfpujtzzsslmmapalrsvsrryusenunn","ntdhewidobpdnrsnclgxdzqetkijeywrtbbxylboosrcjmrnzzkfbcjumtfrrckmfn","kdznspflrqxldxmpcnrnkfipwatjozyyezlypskiijtliiamxrzhxizvkugyvfzagk","avfkenwzzehztftsoscppokyphfqjlckhhwlvukwzuvszqmpkrfahrayyfoiqruzys","kvnxrorpgshuhsnmuvfuvebkordkrdcdzpasfthnlpithxhdunxqtycjrftkixojpq","cukjivasqjpymknlailcrdjmnrjddyufvgqdbrvsamspwhaypmcgpnsehdkkegrzmh","epabjdnbsmiumzgrfxezeldoxhwogiykzyljdamvmxqzwyscwwbaieqfnmwvwuhvss","eyvrvholikmaoizskjwaqmomhkgphbjozefwoviyhwbweaoqlmsbagoiswzzzipapu","xdrhdzdgxjinztbtvcblmtjlujtklkgipyrtzuzyfingdozysaletvpqglcrvicnit","gjqhjvrwcvlbvdehkzebpmmrfkchxmdfwtmfqecubpwwucdebjgrvukbgokfbpkxkz","ebfivgxtcsviyxrgqpbaqjpcpqszpcytdfeblbuqvsywprcfgfhypybeotdfvebbjf","cxiyneqlaheemlkwjzukdlfisbmteyygvjeknxxpebttmdpyclkhwqqptekxcldzuj","jhigynkrgyxxwbihjhzzwsfipktujnfvwodudnojmlikmqrxzswxkegbozxzpfulta","iynwjbjrmxjfvjytgkxmmlolldqholhwjvuswdlibvqweopmypzmanalqqtgeadpxz","kwdvggqwewkvjlkkxlxzypqtvwwalvavrdryljupghmrsxbrkaripjekfalsvnopqh","ndqjuysgpmdsgnszyhicupehhzuxqmedpvpjthpluvdckwbifjmzaqgjsahimlodid","oemgpibuknslwywkxybgivgpfvctylynrntivwcijvthtsssqvyaqhrxcwrchrraem","icikkuhfbczvvsqvsicmgeizjrqarxnzzxjjrtqvvqqqijmcrqoxvwygnpiemvdnvp","yoiojdgawojktcahcxgadtpmadjdqeuotefeklggcrqvuqewokwteohetrjkxgaskf","xurdctxsqrlupbfnwlberxvahugjntpmnirsbomtfxnuaukzhndykaztuhdhastqal","idzuyhunduinvpbyolyphvwkczeypglxlmrjtnwzkgofypeodefmzbwecacripqtbk","exxcwhlknjctzhxetxhrdktfdbuuwxeaubesjpfyyjrzsodnnneqzzxcctwyraanee","gpwnnwwewosbbiohapgysitoimriaxoimkvzhtdfjxgmhxtimbiejbvtoodqltyzev","ynqduzcclkzguohcusdrltfojsjjtnercwwyvzbilaofqxhlpmccgksrecbyrhpweo","ubnvkayyfoyoznacqioiasmbqeiiaowuqjsalqaqeyggoikeryotqdwhhgphvldlwv","nhnnzsohycpiiiiybybxhkewtbjxmhuzqiorceycgomqyupasszcdfywgkvurqvkam","bcqaexqqpomeqgzsiczjaitwcmoawomascawbsoricxziwtrasabavxfhnfgbrgtvi","rxahqkjnltmekmzmnbhmgpznxcgdvcnobpxrzielcqrodqbsuihcxiqulyziamzbdw","sdfzqhphvuawpuhwweeobrncaprztuvlzcmplcxhyxfntmjrtqgwhvyjkridmgrlkd","dwhafgzmvuzfluxtseosqbkygygzlrfonmquupgqjhxvbuovafoqiyroyzqjsvyhho","begiurptotnfopkeiscbicaymtvmafccjkmfcdyqwnvnchrmzwnkyqkmlgalldpund","zrhxidmfqonidogqaeilrtrrfewwamazdjynmmvfaipdyvwzbeksydmfhidhwficoi","pdukkwuzctwasxgesehglqqrznwjpntgqntclpdpizpcywgscnaqfrhegfnxsgfkvy","mjopyyqqbrohlsxmicfrhlxukrdpcyqqheiieayfropfgmrpowixjfuvxxkbxathgb"};
	string word="lcpsvdhalttairlfa";
	*/
	string a[]={"ABCE","SFCS","ADEE"};
	string word="ABCB";
	vector<vector<char>> v(sizeof(a)/sizeof(a[0]));
	for (int i=0;i<v.size();i++){
		v[i]=vector<char>(a[i].c_str(),a[i].c_str()+a[i].length());
	}
	cout<<sol->exist(v,word);
	system("pause");
}