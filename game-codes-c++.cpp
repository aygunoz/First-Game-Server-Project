/*===========================================================================================================
___                          ___ _________   __             ________    ___________    ____              ____   _________
\  \                        /  /|  _ _ _  | |  |           |  ______|  |           |  |    \            /    | |  _ _ _  |
 \  \        ______        /  / | |     | | |  |          |  |        |    _____    | |     \          /     | | |     | |
  \  \      /      \      /  /  | |_ _ _| | |  |         |  |         |   |     |   | |  |\  \        /  /|  | | |_ _ _| |
   \  \    /   /\   \    /  /   |  _ _ _ _| |  |        |  |          |   |     |   | |  | \  \      /  / |  | |  _ _ _ _|
	\  \  /   /  \   \  /  /    | |         |  |        |  |          |   |     |   | |  |  \  \    /  /  |  | | |
	 \  \/   /    \   \/  /     | |         |  |         |  |         |   |_____|   | |  |   \  \  /  /   |  | | |
	  \     /      \     /      | |_ _ _ _  |  |______    |  |______  |             | |  |    \  \/  /    |  | | |_ _ _ _
	   \___/        \___/       |_ _ _ _ _| |_________|    |________|  | __________|  |__|     \____/     |__| |_ _ _ _ _|
//===========================================================================================================
//   ___          ____            ____                ____ _____________________
//  |   |        /   /            \   \              /   /|    |               /
//  |   |       /   /              \   \            /   / |    |              /
//  |   |      /   /                \   \          /   /  |    |             /
//  |   |     /   /                  \   \        /   /   |    |____________/                       /\
//  |   |    /   /                    \   \      /   /    |    |                                 __/  \__
//  |   |   /   /                      \   \    /   /     |    |                                \       /
//  |   |  /   /                        \   \  /   /      |    |                                 \     /
//  |   | /   /                          \   \/   /       |    |                                  \___/
//  |   |/   /            _________       \      /        |    |_________                          ___
//  |   |\   \           |  _ _ _  |       \    /         |    |         |    ______________      |   |
//  |   | \   \          | |     | |       |    |         |    |_________|   |              |     |   |
//  |   |  \   \         | |_ _ _| |       |    |         |    |             |______________|     |   |
//  |   |   \   \        |  _ _ _ _|       |    |         |    |                                  |   |
//  |   |    \   \       | |               |    |         |    |                                  |   |
//  |   |     \   \      | |               |    |         |    |                                  |   |
//  |   |      \   \     | |_ _ _ _        |    |         |    |                                  |   |
//  |___|       \___\    |_ _ _ _ _|       |____|         |____|                                  |___|
//===========================================================================================================
//===========================================================================================================
*/
// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT
//=========================??NCLUDE-PRAGMA===============================
#include <a_samp>
#pragma tabsize 0
#include "L3ADMINv3"
//====================R??TBE S??STEM??====================
//==============KAYIT S??STEM??==============
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/* 1.??ifre Kayd??
* 2.Para Kayd??
* 3.Skor Kayd??
* 4.Ol??m Kayd??
* 5.??ld??rme Kayd??
* 6.Wantedlevel Kayd??
* 7.Skin Kayd??
*/
#include <dudb>
#define Yesil 0x00FF00FF
#define Kirmizi 0xFF0000FF
#define Kayit 1
#define Giris 2
#pragma tabsize 0
enum pplayer
{
   Olme,
   Oldurme,

}
new PlayerInfo[MAX_PLAYERS][pplayer];
new GirisYapti[MAX_PLAYERS];
	new sayi[MAX_PLAYERS];
	new sayma[MAX_PLAYERS];
//=================TAB MENUSU======================
new RainbowError;
new RainbowGradient[25] = {
0xFF0000FF, 0xFF2C00FF, 0xFF5000FF, 0xFF8700FF, 0xFFA700FF,
0xFFDC00FF, 0xFFFB00FF, 0xC4FF00FF, 0x7BFF00FF, 0x00FF00FF,
0x00FF1EFF, 0x00FF3BFF, 0x00FF7CFF, 0x00FFAEFF, 0x00FFD5FF,
0x00FFFFFF, 0x00CCFFFF, 0x00ACFFFF, 0x0083FFFF, 0x0054FFFF,
0x0000FFFF, 0x2C00FFFF, 0x5F00FFFF, 0x9B00FFFF, 0xCB00FFFF
};
//=======================Gerisayin===========================
#define dcmd(%1,%2,%3) \
   if ((strcmp((%3)[1], #%1, true, (%2)) == 0) && ((((%3)[(%2) + 1] == 0) && (dcmd_%1(playerid, "")))||(((%3)[(%2) + 1] == 32) && (dcmd_%1(playerid, (%3)[(%2) + 2]))))) return 1
//haz??r elin deymi??ken ??u komuta level versene
#define ForEach(%0,%1) \
   for(new %0; %0 < %1; %0++) if(IsPlayerConnected(%0))

#define RED                0xFF0000AA

new
   bool: Basladi,
   SayiTimer,
   Miktar;

dcmd_gerisayim(playerid, params[])
{
   if(!strlen(params)) return SendClientMessage(playerid, RED, "<!> /gerisayim [miktar]");
   if(GetPlayerL3AdminLevel(playerid) >= 4)
   {
	   if(!isNumeric(params)) return SendClientMessage(playerid, RED, "<!> Miktarin bir numara olmasi lazim.");
	   if(strval(params) <= 0 || strval(params) >= 15) return SendClientMessage(playerid, RED, "<!> Miktar in 0 dan buyuk ve 15 den kucuk olmasi lazim!");
	   if(Basladi == true) return SendClientMessage(playerid, RED, "<!> Zaten gerisayim baslamis.");
	   new
	      string[64];

	   Miktar = strval(params);
	   format(string, 64, "~y~%d", Miktar);
	   GameTextForAll(string, 950, 6);
	   ForEach(i, MAX_PLAYERS)
	   {
	      PlayerPlaySound(i, 1056, 0.0, 0.0, 0.0);
	      TogglePlayerControllable(i, false);
	   }
	   SayiTimer = SetTimer("GeriSayim", 900, 1);
	   Basladi = true;
	} else {
	    return SendClientMessage(playerid, RED, "<!> Bu Komutu Kullanmaya Leveliniz yetmiyor.");
	}
	return 1;
}

forward GeriSayim();
//====================RENKLER==========================
#define COLOR_ACTIVEBORDER 0xB4B4B4FF
#define COLOR_ACTIVECAPTION 0x99B4D1FF
#define COLOR_ACTIVECAPTIONTEXT 0x000000FF
#define COLOR_ALICEBLUE 0xF0F8FFFF
#define COLOR_ANTIQUEWHITE 0xFAEBD7FF
#define COLOR_APPWORKSPACE 0xABABABFF
#define COLOR_AQUA 0x00FFFFFF
#define COLOR_AQUAMARINE 0x7FFFD4FF
#define COLOR_AZURE 0xF0FFFFFF
#define COLOR_BEIGE 0xF5F5DCFF
#define COLOR_BISQUE 0xFFE4C4FF
#define COLOR_BLACK 0x000000FF
#define COLOR_BLANCHEDALMOND 0xFFEBCDFF
#define COLOR_BLUE 0x0000FFFF
#define COLOR_BLUEVIOLET 0x8A2BE2FF
#define COLOR_BROWN 0xA52A2AFF
#define COLOR_BURLYWOOD 0xDEB887FF
#define COLOR_BUTTONFACE 0xF0F0F0FF
#define COLOR_BUTTONHIGHLIGHT 0xFFFFFFFF
#define COLOR_BUTTONSHADOW 0xA0A0A0FF
#define COLOR_CADETBLUE 0x5F9EA0FF
#define COLOR_CHARTREUSE 0x7FFF00FF
#define COLOR_CHOCOLATE 0xD2691EFF
#define COLOR_CONTROL 0xF0F0F0FF
#define COLOR_CONTROLDARK 0xA0A0A0FF
#define COLOR_CONTROLDARKDARK 0x696969FF
#define COLOR_CONTROLLIGHT 0xE3E3E3FF
#define COLOR_CONTROLLIGHTLIGHT 0xFFFFFFFF
#define COLOR_CONTROLTEXT 0x000000FF
#define COLOR_CORAL 0xFF7F50FF
#define COLOR_CORNFLOWERBLUE 0x6495EDFF
#define COLOR_CORNSILK 0xFFF8DCFF
#define COLOR_CRIMSON 0xDC143CFF
#define COLOR_CYAN 0x00FFFFFF
#define COLOR_DARKBLUE 0x00008BFF
#define COLOR_DARKCYAN 0x008B8BFF
#define COLOR_DARKGOLDENROD 0xB8860BFF
#define COLOR_DARKGRAY 0xA9A9A9FF
#define COLOR_DARKGREEN 0x006400FF
#define COLOR_DARKKHAKI 0xBDB76BFF
#define COLOR_DARKMAGENTA 0x8B008BFF
#define COLOR_DARKOLIVEGREEN 0x556B2FFF
#define COLOR_DARKORANGE 0xFF8C00FF
#define COLOR_DARKORCHID 0x9932CCFF
#define COLOR_DARKRED 0x8B0000FF
#define COLOR_DARKSALMON 0xE9967AFF
#define COLOR_DARKSEAGREEN 0x8FBC8BFF
#define COLOR_DARKSLATEBLUE 0x483D8BFF
#define COLOR_DARKSLATEGRAY 0x2F4F4FFF
#define COLOR_DARKTURQUOISE 0x00CED1FF
#define COLOR_DARKVIOLET 0x9400D3FF
#define COLOR_DEEPPINK 0xFF1493FF
#define COLOR_DEEPSKYBLUE 0x00BFFFFF
#define COLOR_DESKTOP 0x000000FF
#define COLOR_DIMGRAY 0x696969FF
#define COLOR_DODGERBLUE 0x1E90FFFF
#define COLOR_FIREBRICK 0xB22222FF
#define COLOR_FLORALWHITE 0xFFFAF0FF
#define COLOR_FORESTGREEN 0x228B22FF
#define COLOR_FUCHSIA 0xFF00FFFF
#define COLOR_GAINSBORO 0xDCDCDCFF
#define COLOR_GHOSTWHITE 0xF8F8FFFF
#define COLOR_GOLD 0xFFD700FF
#define COLOR_GOLDENROD 0xDAA520FF
#define COLOR_GRADIENTACTIVECAPTION 0xB9D1EAFF
#define COLOR_GRADIENTINACTIVECAPTION 0xD7E4F2FF
#define COLOR_GRAY 0x808080FF
#define COLOR_GRAYTEXT 0x808080FF
#define COLOR_GREEN 0x008000FF
#define COLOR_GREENYELLOW 0xADFF2FFF
#define COLOR_HIGHLIGHT 0x3399FFFF
#define COLOR_HIGHLIGHTTEXT 0xFFFFFFFF
#define COLOR_HONEYDEW 0xF0FFF0FF
#define COLOR_HOTPINK 0xFF69B4FF
#define COLOR_HOTTRACK 0x0066CCFF
#define COLOR_INACTIVEBORDER 0xF4F7FCFF
#define COLOR_INACTIVECAPTION 0xBFCDDBFF
#define COLOR_INACTIVECAPTIONTEXT 0x434E54FF
#define COLOR_INDIANRED 0xCD5C5CFF
#define COLOR_INDIGO 0x4B0082FF
#define COLOR_INFO 0xFFFFE1FF
#define COLOR_INFOTEXT 0x000000FF
#define COLOR_IVORY 0xFFFFF0FF
#define COLOR_KHAKI 0xF0E68CFF
#define COLOR_LAVENDER 0xE6E6FAFF
#define COLOR_LAVENDERBLUSH 0xFFF0F5FF
#define COLOR_LAWNGREEN 0x7CFC00FF
#define COLOR_LEMONCHIFFON 0xFFFACDFF
#define COLOR_LIGHTBLUE 0xADD8E6FF
#define COLOR_LIGHTCORAL 0xF08080FF
#define COLOR_LIGHTCYAN 0xE0FFFFFF
#define COLOR_LIGHTGOLDENRODYELLOW 0xFAFAD2FF
#define COLOR_LIGHTGRAY 0xD3D3D3FF
#define COLOR_LIGHTGREEN 0x90EE90FF
#define COLOR_LIGHTPINK 0xFFB6C1FF
#define COLOR_LIGHTSALMON 0xFFA07AFF
#define COLOR_LIGHTSEAGREEN 0x20B2AAFF
#define COLOR_LIGHTSKYBLUE 0x87CEFAFF
#define COLOR_LIGHTSLATEGRAY 0x778899FF
#define COLOR_LIGHTSTEELBLUE 0xB0C4DEFF
#define COLOR_LIGHTYELLOW 0xFFFFE0FF
#define COLOR_LIME 0x00FF00FF
#define COLOR_LIMEGREEN 0x32CD32FF
#define COLOR_LINEN 0xFAF0E6FF
#define COLOR_MAGENTA 0xFF00FFFF
#define COLOR_MAROON 0x800000FF
#define COLOR_MEDIUMAQUAMARINE 0x66CDAAFF
#define COLOR_MEDIUMBLUE 0x0000CDFF
#define COLOR_MEDIUMORCHID 0xBA55D3FF
#define COLOR_MEDIUMPURPLE 0x9370DBFF
#define COLOR_MEDIUMSEAGREEN 0x3CB371FF
#define COLOR_MEDIUMSLATEBLUE 0x7B68EEFF
#define COLOR_MEDIUMSPRINGGREEN 0x00FA9AFF
#define COLOR_MEDIUMTURQUOISE 0x48D1CCFF
#define COLOR_MEDIUMVIOLETRED 0xC71585FF
#define COLOR_MENU 0xF0F0F0FF
#define COLOR_MENUBAR 0xF0F0F0FF
#define COLOR_MENUHIGHLIGHT 0x3399FFFF
#define COLOR_MENUTEXT 0x000000FF
#define COLOR_MIDNIGHTBLUE 0x191970FF
#define COLOR_MINTCREAM 0xF5FFFAFF
#define COLOR_MISTYROSE 0xFFE4E1FF
#define COLOR_MOCCASIN 0xFFE4B5FF
#define COLOR_NAVAJOWHITE 0xFFDEADFF
#define COLOR_NAVY 0x000080FF
#define COLOR_OLDLACE 0xFDF5E6FF
#define COLOR_OLIVE 0x808000FF
#define COLOR_OLIVEDRAB 0x6B8E23FF
#define COLOR_ORANGE 0xFFA500FF
#define COLOR_ORANGERED 0xFF4500FF
#define COLOR_ORCHID 0xDA70D6FF
#define COLOR_PALEGOLDENROD 0xEEE8AAFF
#define COLOR_PALEGREEN 0x98FB98FF
#define COLOR_PALETURQUOISE 0xAFEEEEFF
#define COLOR_PALEVIOLETRED 0xDB7093FF
#define COLOR_PAPAYAWHIP 0xFFEFD5FF
#define COLOR_PEACHPUFF 0xFFDAB9FF
#define COLOR_PERU 0xCD853FFF
#define COLOR_PINK 0xFFC0CBFF
#define COLOR_PLUM 0xDDA0DDFF
#define COLOR_POWDERBLUE 0xB0E0E6FF
#define COLOR_PURPLE 0x800080FF
#define COLOR_RED 0xFF0000FF
#define COLOR_ROSYBROWN 0xBC8F8FFF
#define COLOR_ROYALBLUE 0x4169E1FF
#define COLOR_SADDLEBROWN 0x8B4513FF
#define COLOR_SALMON 0xFA8072FF
#define COLOR_SANDYBROWN 0xF4A460FF
#define COLOR_SCROLLBAR 0xC8C8C8FF
#define COLOR_SEAGREEN 0x2E8B57FF
#define COLOR_SEASHELL 0xFFF5EEFF
#define COLOR_SIENNA 0xA0522DFF
#define COLOR_SILVER 0xC0C0C0FF
#define COLOR_SKYBLUE 0x87CEEBFF
#define COLOR_SLATEBLUE 0x6A5ACDFF
#define COLOR_SLATEGRAY 0x708090FF
#define COLOR_SNOW 0xFFFAFAFF
#define COLOR_SPRINGGREEN 0x00FF7FFF
#define COLOR_STEELBLUE 0x4682B4FF
#define COLOR_TAN 0xD2B48CFF
#define COLOR_TEAL 0x008080FF
#define COLOR_THISTLE 0xD8BFD8FF
#define COLOR_TOMATO 0xFF6347FF
#define COLOR_TRANSPARENT 0xFFFFFF00
#define COLOR_TURQUOISE 0x40E0D0FF
#define COLOR_VIOLET 0xEE82EEFF
#define COLOR_WHEAT 0xF5DEB3FF
#define COLOR_WHITE 0xFFFFFFFF
#define COLOR_WHITESMOKE 0xF5F5F5FF
#define COLOR_WINDOW 0xFFFFFFFF
#define COLOR_WINDOWFRAME 0x646464FF
#define COLOR_WINDOWTEXT 0x000000FF
#define COLOR_YELLOW 0xFFFF00FF
#define COLOR_YELLOWGREEN 0x9ACD32FF
#define STEALTH_ORANGE 0xFF880000
#define STEALTH_OLIVE 0x66660000
#define STEALTH_GREEN 0x33DD1100
#define STEALTH_PINK 0xFF22EE00
#define STEALTH_BLUE 0x0077BB00
#define GREEN					0x94D317FF
#define ReactionGap				180000
#define green					0x33FF33AA
#define blue					0x00FFFFAA
#define bandialog  110

//-------------------------------------[NEW]--------------------------
new pID[MAX_PLAYERS],Oldu[MAX_PLAYERS];

//======================HIZ S??STEmi==================

new ReactionConsole;
new ReactionGenerator[9];
new ReactionProgress;
new ReactionWinnerid;
new ReactionTime;
new PlayerCash;
new bool: UsedText;

forward ReactionTest();
forward ReactionWin(playerid);
forward SetBack();

//================MYCOLOR=======================
#define Acikmavi 0x00BFFF
#define Acikgri 0xC0C0C0
#define Mavimor 0x7B68EE
#define Tenrengi 0xFFE4E1
#define Orange 0xFF4500
//============================================
#define PARA   15000
#define SANIYE 210
new KaanRank[MAX_PLAYERS];
new Text:EXP[MAX_PLAYERS];
new Text:EXPiM[MAX_PLAYERS];
new Text:Rank[MAX_PLAYERS];
new Text:Rankim[MAX_PLAYERS];
new isimmm[MAX_PLAYER_NAME];
new soru[128], cevap[128];
new PDDOORa;
new PDDOORb;
new PDDOORc;
new PDDOORd;
new PDWINDOW;
new CELLDOOR;
new PDGATE;
new PDGARAGE;
new PDELEVATOR;
new COMPOUNDGATE;
new bycoolnight;
new bycolnight;
new bycooolnight;
//========================LAB??REN S??STEM=================
new labirent2[MAX_PLAYERS];
new labirent;
new labirentkuru;
new labirentkuru2;
#define KIRMIZI 0xAA3333AA
#define SARI 0xFFFF00AA
#define YESIL 0x00DA00AA
//=====================NEW FS Ge??irme Kodlar??==========
#define DIALOGID 1338
new Text:Textdraw0;
new Text:Textdraw1;
static pmodelid[MAX_PLAYERS];
static pvehicleid[MAX_PLAYERS];
//Fowardlar
forward ModCar(playerid);
//-------------------------NEW-------------------
new nos[MAX_PLAYERS] = 0;
new TNOS;
new MaasTimer;
new Text:guardtext;
//====================D??ALOGLAR NEWLER??====================
forward SendPlayerFormattedText(playerid, const str[], define);
//============================<[Yardim]>====================================
new y1_1[] = "{FFFFFF}Ho??geldiniz.Server Hakk??nda Detayl?? Bilgi Sahibi Olmak ????in Mutlaka Okuyunuz.\n";
new y1_2[] = "\nBu Komutu {FF0000}.:[Yaramaz]:.Clan {FFFFFF}Serverine ilk defa girenleri bilgilendirmek i??in tasarlad??m.";
new y1_3[] = "\n{ffffff}Bunun haricinde Serverimizde;\n\n{00FFFF}[Zorunlu Kay??t Sistemi],{00FF7F}[Level sistemi],{D2691E}[Ev Alma Sistemi],{FFD700}[Cete Kurma Sistemi],{FF00FF}[Kendinize ??zel Ara?? Alma Sistemi]\n ";
new y1_4[] = "{008000}[Banka Sistemi],{4682B4}[Shop Men??s??],{7B68EE}[Araclar Men??s??],{FFDAB9}[Arac Modifiye Men??s??],{DCDCDC}[Silahlar Men??s??] {FF4500}mevcut.\n";
new y1_5[] = "{ffffff}Ve Dahas?? ????in {FF0000}[Komutlar] {ffffff}T??klayarak komutlar?? g??r??n??z.";
new y1[1024];
//============================<[Komutlar 1]>====================================
new k1_1[] = "{7B68EE}/araclar        {00FF00}= {FFFFFF}Araba Men??s?? ????kar.\n";
new k1_2[] = "{DCDCDC}/silahlar       {00FF00}= {FFFFFF}Silah Men??s?? ????kar.\n";
new k1_3[] = "{FFDAB9}/modifiye       {00FF00}= {FFFFFF}Arac Modifiye Men??s?? ????kar.\n";
new k1_4[] = "{4682B4}/shop           {00FF00}= {FFFFFF}Kapsaml?? Oyun Men??s?? ????kar.\n";
new k1_5[] = "{00FF7F}/levelim        {00FF00}= {FFFFFF}Leveliniz ve R??tbeniz ????kar.\n";
new k1_6[] = "{00FF7F}/leveller       {00FF00}= {FFFFFF}T??m Leveller ve Expleri ????kar.\n\n{FF0000}/giysi       {00FF00}= {FFFFFF}Elbise men??s?? ????kar.\n";
new k1_7[] = "{C71585}/pm             {00FF00}= {FFFFFF}Bu Komutla Mesaj yollars??n??z.\n";
new k1_8[] = "{008000}/parayolla      {00FF00}= {FFFFFF}Bu Komutla Para yollars??n??z.\n";
new k1_9[] = "{F0E68C}[/skin][/myskin][/k??yafet]{00FF00}={FFFFFF}(Skin ??D).\n";
new k1_10[] = "{D2691E}/evyardim       {00FF00}= {FFFFFF}Ev Sistemi hakk??nda bilgi verir.\n";
new k1_11[] = "{FF00FF}/aracyard??m     {00FF00}= {FFFFFF}Ara?? sistemi hakk??nda bilgi verir.\n";
new k1_12[] = "{00FF00}/banktele       {00FF00}= {FFFFFF}Banka i??lemleriniz i??in bankaya gidersiniz.\n";
new k1_13[] = "{00FFFF}/teles          {00FF00}= {FFFFFF}Teleport Komutlar?? ????kar.\n";
new k1[1024];
//===========================<[Teles]>==============================
new t1_1[] = "{00FFFF}1.Modifiyeciler :{DCDCDC} /mod1  /mod2  /mod3\n";
new t1_2[] = "{00FFFF}2.Drift Yerleri :{DCDCDC} /drift1 /drift2 /drift3 /drift4\n";
new t1_3[] = "{00FFFF}3.Hava Alanlar?? :{DCDCDC} /havaalani1 /havaalani2 /havaalani3 /havaalani4\n";
new t1_4[] = "\n{00FFFF}4.Polis Alanlar?? :{DCDCDC}/polis1 /polis2 /polis3\n";
new t1_5[] = "{00FFFF}5.Yari?? & E??lence Alanlar?? : {DCDCDC}/yaris /carpisanaraba /jump /jump2\n{00FFFF}";
new t1_6[] = "{00FFFF}6.Stunt Alanlar?? :{DCDCDC} /stunt1 /stunt2 /stunt3 /stunt4\n";
new t1_7[] = "{00FFFF}7.Di??er Alanlar :{DCDCDC} /4dragon  /tenis /park /ap1,2,3,4 /sahil\n";
new t1_8[] = "{00FFFF}8.Admin ve ??ete Evleri : {DCDCDC}/babajanev /adminevi2 /adminevi3\n/adminevi4 /iskenderev /yaramazev /ceteevi /ceteevi2\n";
new t1_9[] = "{00FF00}9.Dagl??k Alanlar:{DCDCDC}/dag /dag2 /dag3";
new t1[1024];
//==========================<[Meslekler]>=============================
new m1_1[] = "{FF0000}/haberci        {00FF00}= {FFFFFF}Haberci olursunuz.\n";
new m1_2[] = "{FF0000}/fb??        {00FF00}= {FFFFFF}FBI olursunuz.\n";
new m1_3[] = "{FF0000}/bokscu        {00FF00}= {FFFFFF}Bokscu olursunuz.\n";
new m1_4[] = "{FF0000}/asker        {00FF00}= {FFFFFF}Asker olursunuz.\n";
new m1_5[] = "{FF0000}/otob??sc??        {00FF00}= {FFFFFF}Otob??sc?? olursunuz.\n";
new m1_6[] = "{FF0000}/cete        {00FF00}= {FFFFFF}Cete eleman?? olursunuz.\n";
new m1_7[] = "{FF0000}/koruma        {00FF00}= {FFFFFF}Koruma olursunuz.\n";
new m1_8[] = "{FF0000}/mafya        {00FF00}= {FFFFFF}Mafya olursunuz.\n";
new m1_9[] = "{FF0000}/polis        {00FF00}= {FFFFFF}Polis olursunuz.\n";
new m1_10[] = "{FF0000}/galerici        {00FF00}= {FFFFFF}Galerici olursunuz.\n";
new m1_11[] = "{FF0000}/pilot        {00FF00}= {FFFFFF}Pilot olursunuz.\n";
new m1_12[] = "{FF0000}/komando        {00FF00}= {FFFFFF}Komando olursunuz.\n";
new m1_13[] = "{FF0000}/taksici        {00FF00}= {FFFFFF}Taksici olursunuz.\n";
new m1_14[] = "{FF0000}/yarisci        {00FF00}= {FFFFFF}Rally'ci olursunuz.\n";
new m1_15[] = "{FF0000}/swat        {00FF00}= {FFFFFF}Swat olursunuz.\n";
new m1_16[] = "{FF0000}/benzinci        {00FF00}= {FFFFFF}Pompaci olursunuz.\n";
new m1_17[] = "{FF0000}/serseri        {00FF00}= {FFFFFF}Serseri olursunuz.\n";
new m1_18[] = "{FF0000}/lokantaci        {00FF00}= {FFFFFF}Lokantaci olursunuz.\n";
new m1_19[] = "{FF0000}/tamirci        {00FF00}= {FFFFFF}Tamirci olursunuz.\n";
new m1[1024];
//==========================<[Animasyonlar]>================
new a1_1[] = "{FF0000}/sarhos     {00FF00}= {FFFFFF}Sarhos olursunuz.\n";
new a1_2[] = "{FF0000}/sexy     {00FF00}= {FFFFFF}Sexy hareketler yapars??n??z.\n";
new a1_3[] = "{FF0000}/hirsizlik     {00FF00}= {FFFFFF}Kapkacci mesle??i i??indir.\n";
new a1_4[] = "{FF0000}/nevarlan     {00FF00}= {FFFFFF}Artistlik yapars??n??z.\n";
new a1_5[] = "{FF0000}/sex1-/sex2-/sex3-/sex4-/sex5-/sex6 {00FF00}= {FFFFFF}No Description.\n";
new a1_6[] = "{FF0000}/yemek     {00FF00}= {FFFFFF}Yemek yersiniz.\n";
new a1_7[] = "{FF0000}/elsalla     {00FF00}= {FFFFFF}El sallars??n??z.\n";
new a1_8[] = "{FF0000}/tokat     {00FF00}= {FFFFFF}Tokat atars??n??z.\n";
new a1_9[] = "{FF0000}/op     {00FF00}= {FFFFFF}??p??c??k.\n";
new a1_10[] = "{FF0000}/emrah     {00FF00}= {FFFFFF}Emrah taklidi.\n";
new a1_11[] = "{FF0000}/i??e     {00FF00}= {FFFFFF}??i?? yapars??n??z..\n";
new a1[1024];
//==========================================================
public OnFilterScriptInit()
{
ReactionConsole = SetTimer("ReactionTest", ReactionGap, 1);
			print("\n----------------------------------");
		print("  [Yaramaz] Clan Server\n");
		print("         Hazirlayan");
		print("         Iskender");
		print("----------------------------------\n");
	return 1;
}

public OnFilterScriptExit()
{
KillTimer(ReactionConsole);
	return 1;
}



main()
{
			print("\n----------------------------------");
		print("  [Yaramaz] Clan Server\n");
		print("         Hazirlayan");
		print("         Iskender");
		print("----------------------------------\n");
}

public OnPlayerText(playerid, text[])
{

//================HIZ S??STEM??====================
if(!strcmp(text, ReactionGenerator, false))
        {
                if(ReactionProgress == 2) ReactionWin(playerid);
                if(ReactionProgress == 1)
                {
                        if(ReactionWinnerid == playerid)
                        {
                        SendClientMessage(playerid,GREEN," [H??ZTEST??] : {FF0000} Hiz Testine Hazir Ol !");
                        }
                        else
                        {
                        SendClientMessage(playerid,GREEN,"[H??ZTEST??] : {FF0000} ??ok Yava??s??n ??zg??n??m :-(");
                        }
                }
                return 1;
        }
else
{
new string[128];

    format(string, sizeof(string), "{FF0000}(%i){FFFFFF} %s", playerid, text);
    SendPlayerMessageToAll(playerid, string);
    }
    return 0;
}

public OnPlayerConnect(playerid)
{

TextDrawShowForPlayer(playerid,guardtext);
pID[playerid] = false,Oldu[playerid] = false;
//====================================G??R????DE YAZANLAR=======================
SendClientMessage(playerid,COLOR_WHITE, " _         _                                                                   ");
SendClientMessage(playerid,COLOR_WHITE, "|  |       |  |                                                                  ");
//-----------------------------------------------------------------------
labirent2[playerid] = 0;
GameTextForPlayer(playerid, "~w~[Yaramaz] Clan Server",5000,5);
//=============================KAY??T===============================
        TogglePlayerSpectating(playerid, 1);
	    GirisYapti[playerid] = 0;
        new dosya[256], string[256];
        new isimm[MAX_PLAYER_NAME];
        GetPlayerName(playerid, isimm, sizeof(isimm));
        format(dosya,sizeof(dosya),"KeYF-i/%s.ini",isimm);
        if(!fexist(dosya))
        {

            format(string, sizeof string, "{D3D3D3}Ho??geldin {00FFFF}%s\n{D3D3D3}Sunucumuzda Sizin Ad??n??za Kay??tl?? Bir Hesap Bulunamad??\nL??tfen ??ifre Girin Ve Kay??t Olun.!", isimm);
            ShowPlayerDialog(playerid,Kayit,DIALOG_STYLE_INPUT, "{FF1493}[Yaramaz] Clan Server", string,"Kayit", "??ptal");
        }
if(fexist(dosya))
{
   format(string, sizeof string, "{D3D3D3}Ho??geldin {00FFFF}%s \n{D3D3D3}Sunucumuzda Hesab??n Bulunmaktad??r\nL??tfen ??ifre Yaz??p Giri?? Yap??n??z.",isimm);
   ShowPlayerDialog(playerid,Giris,DIALOG_STYLE_INPUT, "{FF1493}[Yaramaz] Clan Server", string, "Giri??","??ptal");
}
//=============================TAB MENUSU=====================
for(new i = GetMaxPlayers() - 1; i >= 0; --i)
	{
	    if(i == sizeof(RainbowGradient)) RainbowError = 0;
	    if(IsPlayerConnected(i))
	    {
	        SetPlayerColor(i, RainbowGradient[i + RainbowError]);
	    }
	    else RainbowError -= 1;
	}
return 0;
}

public OnPlayerDisconnect(playerid, reason)
{
//===============================TAB MENUSU======================
for(new i = GetMaxPlayers() - 1; i >= 0; --i)
	{
	    if(i == sizeof(RainbowGradient)) RainbowError = 0;
	    if(IsPlayerConnected(i))
	    {
	        SetPlayerColor(i, RainbowGradient[i - RainbowError]);
	    }
	    else RainbowError += 1;
	}
//============================KAY??T S??STEM??=============================
new dosya[128];
new isimm[MAX_PLAYER_NAME];
GetPlayerName(playerid, isimm, sizeof(isimm));
format(dosya,sizeof(dosya),"KeYF-i/%s.ini",isimm);
if(fexist(dosya))
{
	new Float:SX, Float:SY, Float:SZ;
	GetPlayerPos(playerid,SX,SY,SZ);
	dini_IntSet(L3,"Level",p[playerid][Level]);
	dini_IntSet(L3,"Para",GetPlayerMoney(playerid));
	dini_IntSet(L3,"Skor",GetPlayerScore(playerid));
	dini_IntSet(L3,"Skin",GetPlayerSkin(playerid));
	dini_IntSet(L3,"Mute",mute[playerid]);
	dini_IntSet(L3,"Hapis",hapiste[playerid]);
	dini_IntSet(L3,"Silah",GetPlayerWeapon(playerid));
	dini_IntSet(L3,"Mermi",GetPlayerAmmo(playerid));
    dini_FloatSet(L3,"X",SX);
	dini_FloatSet(L3,"Y",SY);
	dini_FloatSet(L3,"Z",SZ);
	dini_IntSet(L3,"I",GetPlayerInterior(playerid));
	dini_IntSet(L3,"Spawn",spawn[playerid]);
    dini_IntSet(dosya,"Skor", GetPlayerScore(playerid));
    dini_IntSet(dosya,"Para", GetPlayerMoney(playerid));
    dini_IntSet(dosya,"Olme", PlayerInfo[playerid][Olme]);
    dini_IntSet(dosya,"Oldurme",PlayerInfo[playerid][Oldurme]);
    dini_IntSet(dosya,"WantedLevel",GetPlayerWantedLevel(playerid));
    dini_IntSet(dosya,"Skinid",GetPlayerSkin(playerid));


  }

  GirisYapti[playerid] =0;
	return 1;
}

public OnPlayerSpawn(playerid)
{
    GangZoneShowForPlayer(playerid, bycoolnight, 0xFF000096);
    GangZoneShowForPlayer(playerid, bycooolnight, 0x0000FF96);
    TextDrawShowForPlayer(playerid, EXP[playerid]);
	TextDrawShowForPlayer(playerid, EXPiM[playerid]);
	TextDrawShowForPlayer(playerid, Rank[playerid]);
	TextDrawShowForPlayer(playerid, Rankim[playerid]);
	return 1;
}


public OnPlayerCommandText(playerid, cmdtext[])
{
	new cmd[256], idx;
	cmd = strtok(cmdtext, idx);
//========================Para yollama================
new string[256];
new sendername[MAX_PLAYER_NAME];
new giveplayer[MAX_PLAYER_NAME];
new moneys;
new
       giveplayerid
;
if(strcmp(cmd, "/parayolla", true) == 0) {
       new tmp[256];
      tmp = strtok(cmdtext, idx);

      if(!strlen(tmp)) {
         SendClientMessage(playerid,COLOR_SADDLEBROWN, "Kullan??m?? : /parayolla [ID] [miktar]");
         return 1;
      }
      giveplayerid = strval(tmp);

      tmp = strtok(cmdtext, idx);
      if(!strlen(tmp)) {
         SendClientMessage(playerid,COLOR_SADDLEBROWN, "Kullan??m?? : /parayolla [ID] [miktar]");
         return 1;
      }
       moneys = strval(tmp);
      if (IsPlayerConnected(giveplayerid)) {
         GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
         GetPlayerName(playerid, sendername, sizeof(sendername));
         new playermoney = GetPlayerMoney(playerid);
         if (moneys > 0 && playermoney >= moneys) {
            GivePlayerMoney(playerid, (0 - moneys));
            GivePlayerMoney(giveplayerid, moneys);
            format(string, sizeof(string), "Para Yolladin %s(player: %d), $%d.", giveplayer,giveplayerid, moneys);
            SendClientMessage(playerid, COLOR_YELLOW, string);
            format(string, sizeof(string), "You have recieved $%d from %s(player: %d).", moneys, sendername, playerid);
            SendClientMessage(giveplayerid, COLOR_YELLOW, string);
            printf("%s(playerid:%d) has transfered %d to %s(playerid:%d)",sendername, playerid, moneys, giveplayer, giveplayerid);
         }
         else {
            SendClientMessage(playerid, COLOR_YELLOW, "Yeterli paran yok.");
         }
      }
      else {
            format(string, sizeof(string), "%d Para Transfer Ettin.", giveplayerid);
            SendClientMessage(playerid, COLOR_YELLOW, string);
         }
return 1;
}
//================================[Meslekler]=============================
if(!strcmp(cmdtext, "/meslekler", true))
    {
   format(m1, sizeof(m1), "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s", m1_1, m1_2, m1_3, m1_4, m1_5, m1_6, m1_7, m1_8, m1_9, m1_10, m1_11, m1_12, m1_13, m1_14, m1_15, m1_16, m1_17, m1_18, m1_19);
ShowPlayerDialog(playerid,5013, DIALOG_STYLE_MSGBOX, "{ffffff}Meslekler",m1, "Animasyonlar", "????k????");
new yazi1[24],yazi2[48];
	GetPlayerName(playerid, yazi1, 24);
	format(yazi2, 48, "%s Adl?? Oyuncu [/meslekler] Bak??yor.", yazi1);
	SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
//================================[Animasyonlar]=============================
if(!strcmp(cmdtext, "/animasyonlar", true))
    {
   format(a1, sizeof(a1), "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", a1_1, a1_2, a1_3, a1_4, a1_5, a1_6, a1_7, a1_8, a1_9, a1_10, a1_11);
ShowPlayerDialog(playerid,5014, DIALOG_STYLE_MSGBOX, "{ffffff}Animasyonlar",a1, "Finish!", "????k????");
new yazi1[24],yazi2[48];
	GetPlayerName(playerid, yazi1, 24);
	format(yazi2, 48, "%s Adl?? Oyuncu [/animasyonlar] Bak??yor.", yazi1);
	SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
//================================[Komutlar]=============================
if(!strcmp(cmdtext, "/komutlar", true))
    {
   format(k1, sizeof(k1), "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s", k1_1, k1_2, k1_3, k1_4, k1_5, k1_6, k1_7, k1_8, k1_9, k1_10, k1_11, k1_12, k1_13);
ShowPlayerDialog(playerid,5011, DIALOG_STYLE_MSGBOX, "{7B68EE}Komutlar",k1, "Teles", "????k????");
new yazi1[24],yazi2[48];
	GetPlayerName(playerid, yazi1, 24);
	format(yazi2, 48, "%s Adl?? Oyuncu [/komutlar] Bak??yor.", yazi1);
	SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
//================================[YARDIM]=============================
if(!strcmp(cmdtext, "/yard??m", true) || !strcmp(cmdtext, "/yardim", true))
    {
    format(y1, sizeof(y1), "%s\n%s\n%s%s\n%s\n", y1_1, y1_2, y1_3, y1_4, y1_5);
ShowPlayerDialog(playerid,5010, DIALOG_STYLE_MSGBOX, "{FF0000}Yard??m",y1, "Komutlar", "????k????");
new yazi1[24],yazi2[48];
	GetPlayerName(playerid, yazi1, 24);
	format(yazi2, 48, "%s Adl?? Oyuncu [/yardim] Bak??yor.", yazi1);
	SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
//------------------------------[Teles]------------------------
   if(!strcmp(cmdtext, "/teles", true))
    {
     format(t1, sizeof(t1), "%s\n%s\n%s%s\n%s\n%s\n%s\n%s\n%s", t1_1, t1_2, t1_3, t1_4, t1_5, t1_6, t1_7, t1_8, t1_9);
    ShowPlayerDialog(playerid,5012, DIALOG_STYLE_MSGBOX, "{FF1493}Teles",t1, "Meslekler", "????k????");
    new yazi1[24],yazi2[48];
	GetPlayerName(playerid, yazi1, 24);
	format(yazi2, 48, "%s Adl?? Oyuncu [/teles] Bak??yor.", yazi1);
	SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
if(!strcmp(cmdtext, "/dag", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
GivePlayerWeapon(playerid,46,10);
	return SetVehiclePos(vehicleid,-1418.898071,-959.131835,201.970291),
    GameTextForPlayer(playerid, "~w~Balta Girmemis Daga Hosgeldiniz.", 5000, 5);
  }
  SetPlayerPos(playerid,-1418.898071,-959.131835,201.970291);
  GameTextForPlayer(playerid, "~w~Balta Girmemis Daga Hosgeldiniz.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/dag] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
//===========================[A??-Kapat Komutlar??]=====================
if (strcmp(cmdtext, "/pd1op", true)==0)
       {
       MoveObject(PDDOORa,247.005905 , 72.448440 , 1003.640625,3.5);//close
       MoveObject(PDDOORa,247.005905 , 72.448440 , 1006.912902,3.5);//open
      SendClientMessage(playerid, COLOR_YELLOW,"Administration Door Open");
      return 1;
       }

		if (strcmp(cmdtext, "/pd1cl", true)==0)
       {
       MoveObject(PDDOORa,247.005905 , 72.448440 , 1006.912902,3.5);//open
       MoveObject(PDDOORa,247.005905 , 72.448440 , 1003.640625,3.5);//close
      SendClientMessage(playerid, COLOR_YELLOW,"Administration Door Close");
      return 1;
       }

       if (strcmp(cmdtext, "/pd2op", true)==0)
       {
       MoveObject(PDDOORb,250.774871 , 60.822799 , 1003.640625,3.5);//close
       MoveObject(PDDOORb,250.774871 , 60.822799 , 1006.862670,3.5);//open
      SendClientMessage(playerid, COLOR_YELLOW,"Desk Door 2 Open");
      return 1;
       }

		if (strcmp(cmdtext, "/pd2cl", true)==0)
       {
       MoveObject(PDDOORb,250.774871 , 60.822799 , 1006.862670,3.5);//open
       MoveObject(PDDOORb,250.774871 , 60.822799 , 1003.640625,3.5);//close
      SendClientMessage(playerid, COLOR_YELLOW,"Desk Door 2 Close");
      return 1;
       }

       if (strcmp(cmdtext, "/pd3op", true)==0)
       {
       MoveObject(PDDOORc,248.142105 , 78.125961 , 1003.640625,3.5);//close
       MoveObject(PDDOORc,248.142105 , 78.125961 , 1007.248718,3.5);//open
      SendClientMessage(playerid, COLOR_YELLOW,"Locker Room Open");
      return 1;
       }

		if (strcmp(cmdtext, "/pd3cl", true)==0)
       {
       MoveObject(PDDOORc,248.142105 , 78.125961 , 1007.248718,3.5);//open
       MoveObject(PDDOORc,248.142105 , 78.125961 , 1003.640625,3.5);//close
      SendClientMessage(playerid, COLOR_YELLOW,"Locker Room Close");
      return 1;
       }

       if (strcmp(cmdtext, "/pd4op", true)==0)
       {
       MoveObject(PDDOORd,248.248901 , 87.360313 , 1003.467834,3.5);//close
       MoveObject(PDDOORd,248.248901 , 87.360313 , 1006.931152,3.5);//open
      SendClientMessage(playerid, COLOR_YELLOW,"Cell Entrance Open");
      return 1;
       }

		if (strcmp(cmdtext, "/pd4cl", true)==0)
       {
       MoveObject(PDDOORd,248.248901 , 87.360313 , 1006.931152,3.5);//open
       MoveObject(PDDOORd,248.248901 , 87.360313 , 1003.467834,3.5);//close
      SendClientMessage(playerid, COLOR_YELLOW,"Cell Entrance Close");
      return 1;
       }

       if (strcmp(cmdtext, "/pdwop", true)==0)
       {
       MoveObject(PDWINDOW,250.503234 , 67.772872 , 1006.222045,3.5);//close
       MoveObject(PDWINDOW,250.503234 , 67.772872 , 1008.109191,3.5);//open
      SendClientMessage(playerid, COLOR_YELLOW,"Window Open");
      return 1;
       }

		if (strcmp(cmdtext, "/pdwcl", true)==0)
       {
       MoveObject(PDWINDOW,250.503234 , 67.772872 , 1008.109191,3.5);//open
       MoveObject(PDWINDOW,250.503234 , 67.772872 , 1006.222045,3.5);//close
      SendClientMessage(playerid, COLOR_YELLOW,"Window Close");
      return 1;
       }

       if (strcmp(cmdtext, "/celop", true)==0)
       {
       MoveObject(CELLDOOR,266.238403 , 81.891395 , 1001.039062,3.5);//close
       MoveObject(CELLDOOR,266.238403 , 81.891395 , 1004.377380,3.5);//open
      SendClientMessage(playerid, COLOR_YELLOW,"Celldoor Open");
      return 1;
       }

		if (strcmp(cmdtext, "/celcl", true)==0)
       {
       MoveObject(CELLDOOR,266.238403 , 81.891395 , 1004.377380,3.5);//open
       MoveObject(CELLDOOR,266.238403 , 81.891395 , 1001.039062,3.5);//close
      SendClientMessage(playerid, COLOR_YELLOW,"Celldoor Close");
      return 1;
       }
if (strcmp(cmdtext, "/girisac", true)==0)
       {
       MoveObject(PDGATE,1546.113769 , -1621.810913 , 11.709331,3.5);//close
       MoveObject(PDGATE,1546.113769 , -1621.810913 , 5.644468,3.5);//open
      SendClientMessage(playerid, COLOR_YELLOW,"LSPD'ye Ho??geldiniz, Kap?? A????ld??.");
      return 1;
       }

		if (strcmp(cmdtext, "/giriskapat", true)==0)
       {
       MoveObject(PDGATE,1546.113769 , -1621.810913 , 5.644468,3.5);//open
       MoveObject(PDGATE,1546.113769 , -1621.810913 , 11.709331,3.5);//close
      SendClientMessage(playerid, COLOR_YELLOW,"Kap?? Kapand??.");
      return 1;
       }

       if (strcmp(cmdtext, "/garajac", true)==0)
       {
       MoveObject(PDGARAGE,1593.301635 , -1638.118530 , 12.467614,3.5);//close
       MoveObject(PDGARAGE,1593.301635 , -1638.118530 , 6.142154,3.5);//open
      SendClientMessage(playerid, COLOR_YELLOW,"Garaj A????ld??.");
      return 1;
       }

		if (strcmp(cmdtext, "/garajkapat", true)==0)
       {
       MoveObject(PDGARAGE,1593.301635 , -1638.118530 , 6.142154,3.5);//open
       MoveObject(PDGARAGE,1593.301635 , -1638.118530 , 12.467614,3.5);//close
      SendClientMessage(playerid, COLOR_YELLOW,"Garaj Kapand??.");
      return 1;
       }

       if (strcmp(cmdtext, "/asansory", true)==0)
       {
       MoveObject(PDELEVATOR,1549.049804 , -1697.787109 , 12.551495,3.5);//down
       MoveObject(PDELEVATOR,1549.049804 , -1697.787109 , 27.134717,3.5);//up
      SendClientMessage(playerid, COLOR_YELLOW,"Asans??r Yukar?? ????k??yor.");
      return 1;
       }

		if (strcmp(cmdtext, "/asansora", true)==0)
       {
       MoveObject(PDELEVATOR,1549.049804 , -1697.787109 , 27.134717,3.5);//up
       MoveObject(PDELEVATOR,1549.049804 , -1697.787109 , 12.551495,3.5);//down
      SendClientMessage(playerid, COLOR_YELLOW,"Asans??r A??a???? ??niyor.");
      return 1;
       }

       if (strcmp(cmdtext, "/carabaac", true)==0)
       {
       MoveObject(COMPOUNDGATE,1591.682861 , -1617.880371 , 12.053466,3.5);//close
       MoveObject(COMPOUNDGATE,1583.598754 , -1617.880371 , 12.053466,3.5);//open
      SendClientMessage(playerid, COLOR_YELLOW,"??arp????an Arabalar Giri?? Kap??s?? A????ld??.");
      return 1;
       }

		if (strcmp(cmdtext, "/carabakapat", true)==0)
       {
       MoveObject(COMPOUNDGATE,1583.598754 , -1617.880371 , 12.053466,3.5);//open
       MoveObject(COMPOUNDGATE,1591.682861 , -1617.880371 , 12.053466,3.5);//close
      SendClientMessage(playerid, COLOR_YELLOW,"??arp????an Arabalar Giri?? Kap??s?? Kapand??.");
      return 1;
       }
if(strcmp("/ceteeviac", cmdtext, true) == 0)
	{
   MoveObject(bycolnight,1492.980347, -699.876587, 98.750000, 4);
   SendClientMessage(playerid, 0xAAAAAAAA, "??ete Evi : Kap?? A????l??yor.");
   return 1;
}
if(strcmp("/ceteevikapat", cmdtext, true) == 0)
	{
   MoveObject(bycolnight,1492.980347, -699.876587, 93.750000, 4);
   SendClientMessage(playerid, 0xAAAAAAAA, "??ete Evi : Kap?? Kapan??yor.");
   return 1;
}
if(!strcmp(cmdtext, "/dag2", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
GivePlayerWeapon(playerid,46,10);
	return SetVehiclePos(vehicleid,1117.963623,-2036.983276,78.750000),
    GameTextForPlayer(playerid, "~w~Balta Girmemis Daga Hosgeldiniz.", 5000, 5);
  }
  SetPlayerPos(playerid,1117.963623,-2036.983276,78.750000);
  GameTextForPlayer(playerid, "~w~Balta Girmemis Daga Hosgeldiniz.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/dag2] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
if(!strcmp(cmdtext, "/dag3", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
GivePlayerWeapon(playerid,46,10);
	return SetVehiclePos(vehicleid,-2230.6467,-1739.8419,481.7216),
    GameTextForPlayer(playerid, "~w~Balta Girmemis Daga Hosgeldiniz.", 5000, 5);
  }
  SetPlayerPos(playerid,-2230.6467,-1739.8419,481.7216);
  GameTextForPlayer(playerid, "~w~Balta Girmemis Daga Hosgeldiniz.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/dag3] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
if(!strcmp(cmdtext, "/drift1", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,-274.9351,1535.3416,75.3594),
    GameTextForPlayer(playerid, "~w~Drift Mekanina Hosgeldiniz.", 5000, 5);
  }
  SetPlayerPos(playerid,-274.9351,1535.3416,75.3594);
  GameTextForPlayer(playerid, "~w~Drift Mekanina Hosgeldiniz.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/drift1] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
// Command: /drift2
if(!strcmp(cmdtext, "/drift2", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,2273.3972,1395.4358,42.8203),
    GameTextForPlayer(playerid, "~w~Drift Mekanina Hosgeldiniz.", 5000, 5);
  }
  SetPlayerPos(playerid,2273.3972,1395.4358,42.8203);
  GameTextForPlayer(playerid, "~w~Drift Mekanina Hosgeldiniz.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/drift2] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}

if(!strcmp(cmdtext, "/tenis", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,757.1934,-1259.5237,13.2293),
    GameTextForPlayer(playerid, "~w~Tenis Sahas??na Hosgeldiniz.", 5000, 5);
  }
  SetPlayerPos(playerid,757.1934,-1259.5237,13.2293);
  GameTextForPlayer(playerid, "~w~Tenis Sahas??na Hosgeldiniz.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/tenis] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
// Command: /drift3
if(!strcmp(cmdtext, "/drift3", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,1210.4374,-2037.3204,69.0078),
    GameTextForPlayer(playerid, "~w~Drift Mekanina Hosgeldiniz.", 5000, 5);
  }
  SetPlayerPos(playerid,1210.4374,-2037.3204,69.0078);
  GameTextForPlayer(playerid, "~w~Drift Mekanina Hosgeldiniz.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/drift3] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
// Command: /drift4
if(!strcmp(cmdtext, "/drift4", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,-2399.6096,-613.3132,132.3755),
    GameTextForPlayer(playerid, "~w~Drift Mekanina Hosgeldiniz.", 5000, 5);
  }
  SetPlayerPos(playerid,-2399.6096,-613.3132,132.3755);
  GameTextForPlayer(playerid, "~w~Drift Mekanina Hosgeldiniz.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/drift4] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
// Command: /adminevi1
if(!strcmp(cmdtext, "/babajanev", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,-695.18, 920.32, 12.29),
    GameTextForPlayer(playerid, "~w~Babajan'in Mekanina Hosgeldin.", 5000, 5);
  }
  SetPlayerPos(playerid,-695.18, 920.32, 12.29);
  GameTextForPlayer(playerid, "~w~Babajan'in Mekanina Hosgeldin.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/babajanev] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
// Command: /havaalani1
if(!strcmp(cmdtext, "/havaalani1", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,1686.7,-2450.2,   13.6),
    GameTextForPlayer(playerid, "~w~Ls Hava Alanina Hosgeldin.", 5000, 5);
  }
  SetPlayerPos(playerid,1686.7,-2450.2,   13.6);
  GameTextForPlayer(playerid, "~w~Ls Hava Alanina Hosgeldin.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/havaalani1] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
// Command: /havaalani2
if(!strcmp(cmdtext, "/havaalani2", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,-1345.0, -229.8,   14.1),
    GameTextForPlayer(playerid, "~w~Sf Hava Alanina Hosgeldin.", 5000, 5);
  }
  SetPlayerPos(playerid,-1345.0, -229.8,   14.1);
  GameTextForPlayer(playerid, "~w~Sf Hava Alanina Hosgeldin.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/havaalani2] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
// Command: /havaalani3
if(!strcmp(cmdtext, "/havaalani3", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,1435.5, 1463.2,   10.8),
    GameTextForPlayer(playerid, "~w~Lv Hava Alanina Hosgeldin.", 5000, 5);
  }
  SetPlayerPos(playerid,1435.5, 1463.2,   10.8);
  GameTextForPlayer(playerid, "~w~Lv Hava Alanina Hosgeldin.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/havaalani3] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
// Command: /havaalani4
if(!strcmp(cmdtext, "/havaalani4", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,350.7, 2539.2,   16.8),
    GameTextForPlayer(playerid, "~w~Desert Air Field Hava Alanina Hosgeldin.", 5000, 5);
  }
  SetPlayerPos(playerid,350.7, 2539.2,   16.8);
  GameTextForPlayer(playerid, "~w~Desert Air Field Hava Alanina Hosgeldin.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/havaalani4] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
// Command: /polis1
if(!strcmp(cmdtext, "/polis1", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,1543.9,-1675.5,   13.6),
    GameTextForPlayer(playerid, "~w~Ls Polis Yerine Hosgeldin", 5000, 5);
  }
  SetPlayerPos(playerid,1543.9,-1675.5,   13.6);
  GameTextForPlayer(playerid, "~w~Ls Polis Yerine Hosgeldin.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/polis1] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
// Command: /polis2
if(!strcmp(cmdtext, "/polis2", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,-1604.7,  718.7,   11.8),
    GameTextForPlayer(playerid, "~w~Sf Polis Yerine Hosgeldin.", 5000, 5);
  }
  SetPlayerPos(playerid,-1604.7,  718.7,   11.8);
  GameTextForPlayer(playerid, "~w~Sf Polis Yerine Hosgeldin.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/polis2] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
// Command: /polis3
if(!strcmp(cmdtext, "/polis3", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,2275.5, 2451.6,   10.5),
    GameTextForPlayer(playerid, "~w~LV Polis Yerine Hosgeldin.", 5000, 5);
  }
  SetPlayerPos(playerid,2275.5, 2451.6,   10.5);
  GameTextForPlayer(playerid, "~w~LV Polis Yerine Hosgeldin.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/polis3] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
if(!strcmp(cmdtext, "/piknik", true))
	{
	new name[256];

				new araba;
		araba=GetPlayerVehicleID(playerid);
		SetVehiclePos(araba, -456.9700,-2479.3562,116.3534);
		PutPlayerInVehicle(playerid,araba,0);
	ResetPlayerWeapons(playerid);
		SetPlayerInterior(playerid,0);
	SetPlayerPos(playerid,-456.9700,-2479.3562,116.3534);
	GetPlayerName(playerid, name, sizeof(name));
	format(string, sizeof(string), "%s Piknik Alan??na Gitti./piknik", name);
	SendClientMessageToAll(COLOR_RED, string);
	SendClientMessage(playerid, COLOR_YELLOW, "Piknik Alanina Hosgeldiniz");
 	DisablePlayerCheckpoint(playerid);
 	GivePlayerMoney(playerid, -100);
	GameTextForPlayer(playerid, "~r~-100$", 2000, 1);

		return 1;
   	}
if(!strcmp(cmdtext, "/ap4", true))
{
GivePlayerWeapon(playerid, 46, 10);
GivePlayerWeapon(playerid, 14, 10);
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,-1742.155029,796.075012,521.502075),
    GameTextForPlayer(playerid, "~w~Ap4 Hosgeldiniz!", 5000, 5);

  }
  SetPlayerPos(playerid,-1742.155029,796.075012,521.502075);
  GameTextForPlayer(playerid, "~w~Ap4 Hosgeldiniz!", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/ap4] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
   	if(!strcmp(cmdtext, "/mod1", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,-1917.2754,287.0215,41.0469),
    GameTextForPlayer(playerid, "~w~Arac Spray!", 5000, 5);
  }
  SetPlayerPos(playerid,-1917.2754,287.0215,41.0469);
  GameTextForPlayer(playerid, "~w~Arac Spray!", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/mod1] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
if(!strcmp(cmdtext, "/mod2", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,-2705.5503, 206.1621, 4.1797),
    GameTextForPlayer(playerid, "~w~Arac Modifiye", 5000, 5);
  }
  SetPlayerPos(playerid,-2705.5503, 206.1621, 4.1797);
  GameTextForPlayer(playerid, "~w~Arac Modifiye", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/mod2] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
if(!strcmp(cmdtext, "/mod3", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,2387.4126,1022.6620,10.8203),
    GameTextForPlayer(playerid, "~w~Arac Spray!", 5000, 5);
  }
  SetPlayerPos(playerid,2387.4126,1022.6620,10.8203);
  GameTextForPlayer(playerid, "~w~Arac Spray!", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/mod3] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
  return 1;
   }
   	if(!strcmp(cmdtext, "/ap1", true)) {
		new araba;
		araba=GetPlayerVehicleID(playerid);
		SetPlayerPos(playerid, -1347.1360,-234.9015,14.1484);
		SetVehiclePos(araba,  -1347.1360,-234.9015,14.1484);
		PutPlayerInVehicle(playerid,araba,0);
        new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/ap1] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
		return 1;
	}
if(!strcmp(cmdtext, "/ap2", true)) {
		new araba;
        araba=GetPlayerVehicleID(playerid);
        SetPlayerPos(playerid, 1317.7917,1260.0190,10.8203);
        SetVehiclePos(araba, 1317.7917,1260.0190,10.8203);
        PutPlayerInVehicle(playerid,araba,0);
        new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/ap2] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
		return 1;
	}
if(!strcmp(cmdtext, "/ap3", true)){
		new araba;
		araba=GetPlayerVehicleID(playerid);
		SetPlayerPos(playerid, 420.2640,2521.1553,16.4844);
		SetVehiclePos(araba, 420.2640,2521.1553,16.4844);
		PutPlayerInVehicle(playerid,araba,0);
        new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/ap3] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
		   return 1;
   }
   	if(!strcmp(cmdtext, "/sahil", true)){
		new araba;
		ResetPlayerWeapons(playerid);
	    SetPlayerPos(playerid,304.2043,-1898.9293,1.7956);
	    SetVehiclePos(araba, 304.2043,-1898.9293,1.7956);
	    PutPlayerInVehicle(playerid,araba,0);
        new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/sahil] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
		return 1;
	}
if(!strcmp(cmdtext, "/stunt2", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,1686.7,-2450.2,   13.6),
    GameTextForPlayer(playerid, "~w~Ls Stunt Mekanina Hosgeldin.", 5000, 5);
  }
  SetPlayerPos(playerid,1686.7,-2450.2,   13.6);
  GameTextForPlayer(playerid, "~w~Ls Stunt Mekanina Hosgeldin.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/stunt2] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
if(!strcmp(cmdtext, "/stunt3", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,-1345.0, -229.8,   14.1),
    GameTextForPlayer(playerid, "~w~San Fierro Stunt Mekanina Hosgeldin.", 5000, 5);
  }
  SetPlayerPos(playerid,-1345.0, -229.8,   14.1);
  GameTextForPlayer(playerid, "~w~San Fierro Stunt Mekanina Hosgeldin.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/stunt3] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
if(!strcmp(cmdtext, "/stunt1", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,1435.5, 1463.2,   10.8),
    GameTextForPlayer(playerid, "~w~Lv Stunt Mekanina Hosgeldin.", 5000, 5);
  }
  SetPlayerPos(playerid,1435.5, 1463.2,   10.8);
  GameTextForPlayer(playerid, "~w~Lv Stunt Mekanina Hosgeldin.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/stunt1] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}

if(!strcmp(cmdtext, "/galeri2", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,-1636.544433, 1203.016235,   7.179687),
    GameTextForPlayer(playerid, "~w~DAF Galeriye Hosgeldin.", 5000, 5);
  }
  SetPlayerPos(playerid,-1636.544433, 1203.016235,   7.179687);
  GameTextForPlayer(playerid, "~w~DAF Galeriye Hosgeldin.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/galeri2] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
if(!strcmp(cmdtext, "/stunt4", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,350.7, 2539.2,   16.8),
    GameTextForPlayer(playerid, "~w~DAF Stunt Mekanina Hosgeldin.", 5000, 5);
  }
  SetPlayerPos(playerid,350.7, 2539.2,   16.8);
  GameTextForPlayer(playerid, "~w~DAF Stunt Mekanina Hosgeldin.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/stunt4] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
if(!strcmp(cmdtext, "/relaxev", true)) {
    SetPlayerPos(playerid, 1235.6501,-2288.0908,13.1681);
    GameTextForPlayer(playerid,"Relaxev'ine Mekanina Hosgeldin.",5000,3);
    new Float:X, Float:Y, Float:Z;
    PlayerPlaySound(playerid, 1083, X, Y, Z);
    new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/relaxev] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
	return 1;
	}
if(!strcmp(cmdtext, "/yaris", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,-2408.6252,-599.6188,132.6484),
    GameTextForPlayer(playerid, "~w~Yaris'a Hosgeldiniz.", 5000, 5);
  }
  SetPlayerPos(playerid,-2408.6252,-599.6188,132.6484);
  GameTextForPlayer(playerid, "~w~Yaris'a Hosgeldiniz.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/yaris] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
if(!strcmp(cmdtext, "/adminevi2", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,-362.66,1165.38,19.74),
    GameTextForPlayer(playerid, "~w~Admin2'in Mekanina Hosgeldin.", 5000, 5);
  }
  SetPlayerPos(playerid,-362.66,1165.38,19.74);
  GameTextForPlayer(playerid, "~w~Admin2'in Mekanina Hosgeldin.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/adminevi2] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
// Command: /ceteevi2
if(!strcmp(cmdtext, "/ceteevi2", true)) {
    SetPlayerPos(playerid, 1588.7805,-1625.3348,13.3828);
    SetPlayerSkin(playerid, 120);
    SetPlayerArmour(playerid,100);
    GameTextForPlayer(playerid, "~w~Ceteevi2'nin Cetesine Hosgeldin.", 5000, 5);
	new yazi1[24],yazi2[48];
  	GetPlayerName(playerid, yazi1, 24);
  	format(yazi2, 48, "%s Adl?? Oyuncu [/ceteevi2] Gitti.", yazi1);
  	SendClientMessageToAll(COLOR_YELLOW, yazi2);
	new Float:X, Float:Y, Float:Z;
    PlayerPlaySound(playerid, 1147, X, Y, Z);
	return 1;
}
// Command: /adminevi4
if(!strcmp(cmdtext, "/adminevi4", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,1339.9077,-626.5864,109.1349),
    GameTextForPlayer(playerid, "~w~Admin4'in Mekanina Hosgeldin.", 5000, 5);
  }
  SetPlayerPos(playerid,1339.9077,-626.5864,109.1349);
  GameTextForPlayer(playerid, "~w~Admin4'in Mekanina Hosgeldin.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/adminevi4] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
// Command: /adminevi5
if(!strcmp(cmdtext, "/iskenderev", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,1300.4329,-813.4969,84.1406),
    GameTextForPlayer(playerid, "~w~??skender'in Mekanina Hosgeldin.", 5000, 5);
  }
  SetPlayerPos(playerid,1300.4329,-813.4969,84.1406);
  GameTextForPlayer(playerid, "~w~??skender'in Mekanina Hosgeldin.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/iskenderev] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
// Command: /adminevi3
if(!strcmp(cmdtext, "/adminevi3", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,322.6174,-1780.6541,4.8187),
    GameTextForPlayer(playerid, "~w~Admin3'in Mekanina Hosgeldin.", 5000, 5);
  }
  SetPlayerPos(playerid,322.6174,-1780.6541,4.8187);
  GameTextForPlayer(playerid, "~w~Admin3'in Mekanina Hosgeldin.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/adminevi3] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
// Command: /caraba
if(!strcmp(cmdtext, "/caraba", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,1572.6154,-1606.7649,13.3828),
    GameTextForPlayer(playerid, "~w~Carpisan Arabalara Hosgeldiniz.", 5000, 5);
  }
  SetPlayerPos(playerid,1572.6154,-1606.7649,13.3828);
  GameTextForPlayer(playerid, "~w~Carpisan Arabalara Hosgeldiniz.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/caraba] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
// Command: /jump
if(!strcmp(cmdtext, "/jump", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,288.9978,-1600.5017,114.4219),
    GameTextForPlayer(playerid, "~w~Jump Yerine Hosgeldiniz.", 5000, 5);
  }
  SetPlayerPos(playerid,288.9978,-1600.5017,114.4219);
  GameTextForPlayer(playerid, "~w~Jump Yerine Hosgeldiniz.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/jump] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
// Command: /jump2
if(!strcmp(cmdtext, "/jump2", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,-2499.8943,-701.6136,279.7707),
    GameTextForPlayer(playerid, "~w~Jump Yerine Hosgeldiniz.", 5000, 5);
  }
  SetPlayerPos(playerid,-2499.8943,-701.6136,279.7707);
  GameTextForPlayer(playerid, "~w~Jump Yerine Hosgeldiniz.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/jump2] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}


	// Command: /4dragon
if(!strcmp(cmdtext, "/4dragon", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,2028.5538, 1008.3543, 10.8203),
    GameTextForPlayer(playerid, "~w~4Dragon'a Hosgeldin.", 5000, 5);
  }
  SetPlayerPos(playerid,2028.5538, 1008.3543, 10.8203);
  GameTextForPlayer(playerid, "~w~4Dragon'a Hosgeldin.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/4dragon] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
	   return 1;
    }
   	if(!strcmp(cmdtext, "/galeri", true))
{
  new vehicleid = GetPlayerVehicleID(playerid);
  new State = GetPlayerState(playerid);
  if(IsPlayerInAnyVehicle(playerid) && State == PLAYER_STATE_DRIVER)
  {
    return SetVehiclePos(vehicleid,-1943.5868,276.7582,41.0471),
    GameTextForPlayer(playerid, "~w~DAF Galeriye Hosgeldin.", 5000, 5);
  }
  SetPlayerPos(playerid,-1943.5868,276.7582,41.0471);
  GameTextForPlayer(playerid, "~w~DAF Galeriye Hosgeldin.", 5000, 5);
  new yazi1[24],yazi2[48];
  GetPlayerName(playerid, yazi1, 24);
  format(yazi2, 48, "%s Adl?? Oyuncu [/galeri] Gitti.", yazi1);
  SendClientMessageToAll(COLOR_YELLOW, yazi2);
return 1;
}
//-------------------------[Animasyonlar]-------------------------------
if(!strcmp(cmdtext, "/sarhos", true)) {
	ApplyAnimation(playerid, "PED", "WALK_DRUNK", 4.0, 1, 1, 1, 1, 0);
	ApplyAnimation(playerid, "PED", "WALK_DRUNK", 4.0, 1, 1, 1, 1, 0);
	return 1;
     }
      if(!strcmp(cmdtext, "/sexy", true)) {
	ApplyAnimation(playerid, "ped", "WOMAN_walksexy", 4.0, 0, 0, 0, 0, 0);
	ApplyAnimation(playerid, "ped", "WOMAN_walksexy", 4.0, 0, 0, 0, 0, 0);
	return 1;
        }
        if(!strcmp(cmdtext, "/hirsizlik", true)) {
	ApplyAnimation(playerid, "SHOP", "ROB_Loop_Threat", 4.0, 1, 0, 0, 0, 0);
	ApplyAnimation(playerid, "SHOP", "ROB_Loop_Threat", 4.0, 1, 0, 0, 0, 0);
	return 1;
        }
       if(!strcmp(cmdtext, "/31", true)) {
	ApplyAnimation(playerid, "PAULNMAC", "wank_loop", 4.0, 1, 0, 0, 0, 0);
	ApplyAnimation(playerid, "PAULNMAC", "wank_loop", 4.0, 1, 0, 0, 0, 0);
 	return 1;
		}
		if(!strcmp(cmdtext, "/31bitis", true)) {
    ApplyAnimation(playerid, "PAULNMAC", "wank_out", 4.0, 0, 0, 0, 0, 0);
    ApplyAnimation(playerid, "PAULNMAC", "wank_out", 4.0, 0, 0, 0, 0, 0);
    return 1;
       }
      if(!strcmp(cmdtext, "/yemek", true)) {
	ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
	ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
	return 1;
       }
      if(!strcmp(cmdtext, "/elsalla", true)) {
	ApplyAnimation(playerid, "ON_LOOKERS", "wave_loop", 3.5, 1, 0, 0, 0, 0);
	ApplyAnimation(playerid, "ON_LOOKERS", "wave_loop", 3.5, 1, 0, 0, 0, 0);
    return 1;
        }
       if(!strcmp(cmdtext, "/tokat", true)) {
   	ApplyAnimation(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0);
	ApplyAnimation(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0);
    return 1;
        }
       if(!strcmp(cmdtext, "/op", true)) {
	ApplyAnimation(playerid, "KISSING", "Grlfrd_Kiss_02", 4.0, 0, 0, 0, 0, 0);
	ApplyAnimation(playerid, "KISSING", "Grlfrd_Kiss_02", 4.0, 0, 0, 0, 0, 0);
    return 1;
    }
    if(!strcmp(cmdtext, "/emrah", true)) {
	ApplyAnimation(playerid, "CRACK", "crckdeth2", 3.5, 1, 0, 0, 0, 0);
	ApplyAnimation(playerid, "CRACK", "crckdeth2", 3.5, 1, 0, 0, 0, 0);
    return 1;
        }
       if(!strcmp(cmdtext, "/i??e", true)) {
	ApplyAnimation(playerid, "PAULNMAC", "Piss_loop", 4.0, 1, 1, 1, 1, 0);
	ApplyAnimation(playerid, "PAULNMAC", "Piss_loop", 4.0, 1, 1, 1, 1, 0);
    return 1;
        }
        if(!strcmp(cmdtext, "/nevarlan", true)) {
    ApplyAnimation(playerid,"ped", "fucku", 4.1, 0, 1, 1, 1, 1 ); // Wave fist / Pull fingers (with block hands)
    ApplyAnimation(playerid,"ped", "fucku", 4.1, 0, 1, 1, 1, 1 ); // Wave fist / Pull fingers (with block hands)
    return 1;
    }
    if(!strcmp(cmdtext, "/sex1", true)) {
	ApplyAnimation(playerid, "PAULNMAC", "wank_loop", 1.8, 1, 0, 0, 1, 600);
	ApplyAnimation(playerid, "PAULNMAC", "wank_loop", 1.8, 1, 0, 0, 1, 600);
    return 1;
    }
    if(!strcmp(cmdtext, "/sex2", true)) {
	ApplyAnimation(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0);
	ApplyAnimation(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0);
    return 1;
    }
    if(!strcmp(cmdtext, "/sex3", true)) {
	ApplyAnimation(playerid, "MISC", "bitchslap", 4.0999, 0, 1, 1, 1, 1);
	ApplyAnimation(playerid, "MISC", "bitchslap", 4.0999, 0, 1, 1, 1, 1);
    return 1;
    }
    if(!strcmp(cmdtext, "/sex4", true)) {
	ApplyAnimation(playerid, "PED", "fucku", 4.0999, 0, 1, 1, 1, 1);
	ApplyAnimation(playerid, "PED", "fucku", 4.0999, 0, 1, 1, 1, 1);
    return 1;
    }
    if(!strcmp(cmdtext, "/sex5", true)) {
	ApplyAnimation(playerid, "BLOWJOBZ", "BJ_COUCH_LOOP_W", 4.0999, 0, 1, 1, 1, 1);
	ApplyAnimation(playerid, "BLOWJOBZ", "BJ_COUCH_LOOP_W", 4.0999, 0, 1, 1, 1, 1);
    return 1;
    }
    if(!strcmp(cmdtext, "/sex6", true)) {
	ApplyAnimation(playerid, "PAULNMAC", "PISS_LOOP", 4.0999, 0, 1, 1, 1, 1);
	ApplyAnimation(playerid, "PAULNMAC", "PISS_LOOP", 4.0999, 0, 1, 1, 1, 1);
    return 1;
    }
//------------------------[Meslekler]-------------------------------------
    if(!strcmp(cmdtext, "/haberci", true)) {
	SetPlayerPos(playerid, 1943.9790,1074.8854,21.8504);
    GivePlayerWeapon(playerid,43,500);
    GivePlayerWeapon(playerid,31,500);
    GivePlayerWeapon(playerid,24,500);
    SetPlayerSkin(playerid, 240);
    SendClientMessage(playerid, 0x00c8ffff, "Haberci Oldun, G??revin Paparazilik Yapmak.");
    new yazi1[24],yazi2[48];
		GetPlayerName(playerid, yazi1, 24);
		format(yazi2, 48, "%s Adl?? Oyuncu Haberci Oldu[/haberci]", yazi1);
		SendClientMessageToAll(COLOR_YELLOW, yazi2);

	return 1;
    }
    if(!strcmp(cmdtext, "/fb??", true)) {
	SetPlayerPos(playerid, 2310.9099,2492.3101,3.2734);
    GivePlayerWeapon(playerid,32,500);
    GivePlayerWeapon(playerid,31,500);
    GivePlayerWeapon(playerid,24,500);
    SetPlayerSkin(playerid, 286);
    SendClientMessage(playerid, 0x00c8ffff, "FBI Oldun, G??revin ??zel ??stihbarat Sa??lamak.");
    new yazi1[24],yazi2[48];
		GetPlayerName(playerid, yazi1, 24);
		format(yazi2, 48, "%s Adl?? Oyuncu FBI Oldu[/fb??]", yazi1);
		SendClientMessageToAll(COLOR_YELLOW, yazi2);

	return 1;
    }
    if(!strcmp(cmdtext, "/bokscu", true)) {
	SetPlayerPos(playerid, 2133.9055,1141.8480,13.5020);
    GivePlayerWeapon(playerid,32,500);
    GivePlayerWeapon(playerid,31,500);
    GivePlayerWeapon(playerid,24,500);
    SetPlayerSkin(playerid, 80);
    SendClientMessage(playerid, 0x00c8ffff, "Bokscu Oldun, G??revin ??nsanlar?? Pataklamak.");
    new yazi1[24],yazi2[48];
		GetPlayerName(playerid, yazi1, 24);
		format(yazi2, 48, "%s Adl?? Oyuncu Bokscu Oldu[/bokscu]", yazi1);
		SendClientMessageToAll(COLOR_YELLOW, yazi2);

	return 1;
    }
    if(!strcmp(cmdtext, "/asker", true)) {
	SetPlayerPos(playerid, 211.3449,1810.1344,21.8672);
    GivePlayerWeapon(playerid,32,500);
    GivePlayerWeapon(playerid,31,500);
    GivePlayerWeapon(playerid,24,500);
    SetPlayerSkin(playerid, 287);
    SendClientMessage(playerid, 0x00c8ffff, "Asker Oldun, G??revin Devletini ve Vatan??n?? Korumak.");
    new yazi1[24],yazi2[48];
		GetPlayerName(playerid, yazi1, 24);
		format(yazi2, 48, "%s Adl?? Oyuncu Asker Oldu[/asker]", yazi1);
		SendClientMessageToAll(COLOR_YELLOW, yazi2);

	return 1;
    }
    if(!strcmp(cmdtext, "/otob??sc??", true)) {
	SetPlayerPos(playerid, -1993.2800,147.2500,27.5391);
    GivePlayerWeapon(playerid,32,500);
    GivePlayerWeapon(playerid,31,500);
    GivePlayerWeapon(playerid,24,500);
    SetPlayerSkin(playerid, 185);
    SendClientMessage(playerid, 0x00c8ffff, "Otob??sc?? Oldun, G??revin ??nsanlar?? Gidecekleri Yere Ula??t??rmak.");
    new yazi1[24],yazi2[48];
		GetPlayerName(playerid, yazi1, 24);
		format(yazi2, 48, "%s Adl?? Oyuncu Otob??sc?? Oldu[/otob??sc??]", yazi1);
		SendClientMessageToAll(COLOR_YELLOW, yazi2);

	return 1;
    }
    if(!strcmp(cmdtext, "/cete", true)) {
	SetPlayerPos(playerid, 2311.5649,1409.2748,42.8203);
    GivePlayerWeapon(playerid,32,500);
    GivePlayerWeapon(playerid,31,500);
    GivePlayerWeapon(playerid,24,500);
    SetPlayerSkin(playerid, 271);
    SendClientMessage(playerid, 0x00c8ffff, "??ete Oldun, G??revin Organize Su?? ve ??nsanlar?? Katletmek.");
    new yazi1[24],yazi2[48];
		GetPlayerName(playerid, yazi1, 24);
		format(yazi2, 48, "%s Adl?? Oyuncu ??ete Oldu[/cete]", yazi1);
		SendClientMessageToAll(COLOR_YELLOW, yazi2);

	return 1;
    }
    if(!strcmp(cmdtext, "/koruma", true)) {
	SetPlayerPos(playerid, -2054.6506,456.3192,35.1719);
    GivePlayerWeapon(playerid,32,500);
    GivePlayerWeapon(playerid,31,500);
    GivePlayerWeapon(playerid,24,500);
    SetPlayerSkin(playerid, 164);
    SendClientMessage(playerid, 0x00c8ffff, "Koruma Oldun, G??revin Patronunu Korumak.");
    new yazi1[24],yazi2[48];
		GetPlayerName(playerid, yazi1, 24);
		format(yazi2, 48, "%s Adl?? Oyuncu Koruma Oldu[/koruma]", yazi1);
		SendClientMessageToAll(COLOR_YELLOW, yazi2);

	return 1;
    }
    if(!strcmp(cmdtext, "/mafya", true)) {
	SetPlayerPos(playerid, -2633.7500,1354.6899,7.1172);
    GivePlayerWeapon(playerid,32,500);
    GivePlayerWeapon(playerid,31,500);
    GivePlayerWeapon(playerid,24,500);
    SetPlayerSkin(playerid, 120);
    SendClientMessage(playerid, 0x00c8ffff, "Mafya Oldun, G??revin Hara?? Toplamak ve ??nsanlar?? ??ld??rmek.");
    new yazi1[24],yazi2[48];
		GetPlayerName(playerid, yazi1, 24);
		format(yazi2, 48, "%s Adl?? Oyuncu Mafya Oldu[/mafya]", yazi1);
		SendClientMessageToAll(COLOR_YELLOW, yazi2);

	return 1;
    }
    if(!strcmp(cmdtext, "/polis", true)) {
	SetPlayerPos(playerid, 1546.5795,-1675.4204,13.5626);
    GivePlayerWeapon(playerid,32,500);
    GivePlayerWeapon(playerid,31,500);
    GivePlayerWeapon(playerid,24,500);
    SetPlayerSkin(playerid, 266);
    SendClientMessage(playerid, 0x00c8ffff, "Polis Oldun, G??revin Su??lular?? Adalete Teslim Etmek.");
    new yazi1[24],yazi2[48];
		GetPlayerName(playerid, yazi1, 24);
		format(yazi2, 48, "%s Adl?? Oyuncu Polis Oldu[/polis]", yazi1);
		SendClientMessageToAll(COLOR_YELLOW, yazi2);

	return 1;
    }
    if(!strcmp(cmdtext, "/kapkacci", true)) {
	SetPlayerPos(playerid, 2460.3811,1958.9724,10.6655);
    GivePlayerWeapon(playerid,32,500);
    GivePlayerWeapon(playerid,31,500);
    GivePlayerWeapon(playerid,24,500);
    SetPlayerSkin(playerid, 29);
    SendClientMessage(playerid, 0x00c8ffff, "Kapka?????? Oldun, G??revin C??zdanlar?? Cebe ??ndirmek.");
    new yazi1[24],yazi2[48];
		GetPlayerName(playerid, yazi1, 24);
		format(yazi2, 48, "%s Adl?? Oyuncu Kapka?????? Oldu[/kapkacci]", yazi1);
		SendClientMessageToAll(COLOR_YELLOW, yazi2);

	return 1;
    }
    if(!strcmp(cmdtext, "/galerici", true)) {
	SetPlayerPos(playerid, -1959.5699,281.2300,35.4688);
    GivePlayerWeapon(playerid,32,500);
    GivePlayerWeapon(playerid,31,500);
    GivePlayerWeapon(playerid,24,500);
    SetPlayerSkin(playerid, 187);
    SendClientMessage(playerid, 0x00c8ffff, "Galerici Oldun, G??revin Araba Satmak.");
    new yazi1[24],yazi2[48];
		GetPlayerName(playerid, yazi1, 24);
		format(yazi2, 48, "%s Adl?? Oyuncu Galerici Oldu[/galerici]", yazi1);
		SendClientMessageToAll(COLOR_YELLOW, yazi2);

	return 1;
    }
    if(!strcmp(cmdtext, "/pilot", true)) {
	SetPlayerPos(playerid, -1326.2458,-243.6935,14.1484);
    GivePlayerWeapon(playerid,32,500);
    GivePlayerWeapon(playerid,31,500);
    GivePlayerWeapon(playerid,24,500);
    SetPlayerSkin(playerid, 255);
    SendClientMessage(playerid, 0x00c8ffff, "Pilot Oldun, G??revin U??ak ??le ??nsanlar?? Gidecekleri Yere Ula??t??rmak.");
    new yazi1[24],yazi2[48];
		GetPlayerName(playerid, yazi1, 24);
		format(yazi2, 48, "%s Adl?? Oyuncu Pilot Oldu[/pilot]", yazi1);
		SendClientMessageToAll(COLOR_YELLOW, yazi2);

	return 1;
    }
    if(!strcmp(cmdtext, "/komando", true)) {
	SetPlayerPos(playerid, 212.9100,1901.5699,17.6406);
    GivePlayerWeapon(playerid,32,500);
    GivePlayerWeapon(playerid,31,500);
    GivePlayerWeapon(playerid,24,500);
    SetPlayerSkin(playerid, 287);
    SendClientMessage(playerid, 0x00c8ffff, "Komando Oldun, G??revin Su??lular?? ve Hainleri ??ld??rmek.");
    new yazi1[24],yazi2[48];
		GetPlayerName(playerid, yazi1, 24);
		format(yazi2, 48, "%s Adl?? Oyuncu Komando Oldu[/komando]", yazi1);
		SendClientMessageToAll(COLOR_YELLOW, yazi2);

	return 1;
    }
    if(!strcmp(cmdtext, "/taksici", true)) {
	SetPlayerPos(playerid, 2030.6019,948.1672,10.0332);
    GivePlayerWeapon(playerid,32,500);
    GivePlayerWeapon(playerid,31,500);
    GivePlayerWeapon(playerid,24,500);
    SetPlayerSkin(playerid, 223);
    SendClientMessage(playerid, 0x00c8ffff, "Taksici Oldun, G??revin Taksi ??le ??nsanlar?? Gidecekleri Yerlere G??t??rmek.");
    new yazi1[24],yazi2[48];
		GetPlayerName(playerid, yazi1, 24);
		format(yazi2, 48, "%s Adl?? Oyuncu Taksici Oldu[/taksici]", yazi1);
		SendClientMessageToAll(COLOR_YELLOW, yazi2);

	return 1;
    }
    if(!strcmp(cmdtext, "/yarisci", true)) {
	SetPlayerPos(playerid, -296.0228,1539.1449,75.5625);
    GivePlayerWeapon(playerid,32,500);
    GivePlayerWeapon(playerid,31,500);
    GivePlayerWeapon(playerid,24,500);
    SetPlayerSkin(playerid, 66);
    SendClientMessage(playerid, 0x00c8ffff, "Yar???????? Oldun, G??revin Yar????lar?? Kazanmak.");
    new yazi1[24],yazi2[48];
		GetPlayerName(playerid, yazi1, 24);
		format(yazi2, 48, "%s Adl?? Oyuncu Yar???????? Oldu[/yarisci]", yazi1);
		SendClientMessageToAll(COLOR_YELLOW, yazi2);

	return 1;
    }
    if(!strcmp(cmdtext, "/swat", true)) {
	SetPlayerPos(playerid, 2307.6001,2487.6499,-7.4531);
    GivePlayerWeapon(playerid,32,500);
    GivePlayerWeapon(playerid,31,500);
    GivePlayerWeapon(playerid,24,500);
    SetPlayerSkin(playerid, 285);
    SendClientMessage(playerid, 0x00c8ffff, "SWAT Oldun, G??revin Gizli ??stihbarat Sa??lamak.");
    new yazi1[24],yazi2[48];
		GetPlayerName(playerid, yazi1, 24);
		format(yazi2, 48, "%s Adl?? Oyuncu SWAT Oldu[/swat]", yazi1);
		SendClientMessageToAll(COLOR_YELLOW, yazi2);

	return 1;
    }
    if(!strcmp(cmdtext, "/benzinci", true)) {
	SetPlayerPos(playerid, 2189.3000,2472.2400,11.2422);
    GivePlayerWeapon(playerid,32,500);
    GivePlayerWeapon(playerid,31,500);
    GivePlayerWeapon(playerid,24,500);
    SetPlayerSkin(playerid, 50);
    SendClientMessage(playerid, 0x00c8ffff, "Benzinci Oldun, G??revin Ara??lara Benzin Vermek.");
    new yazi1[24],yazi2[48];
		GetPlayerName(playerid, yazi1, 24);
		format(yazi2, 48, "%s Adl?? Oyuncu Benzinci Oldu[/benzinci]", yazi1);
		SendClientMessageToAll(COLOR_YELLOW, yazi2);

	return 1;
    }
	if(!strcmp(cmdtext, "/serseri", true)) {
    SetPlayerPos(playerid, -1659.6665,820.6225,18.6077);
    GivePlayerWeapon(playerid,32,500);
    GivePlayerWeapon(playerid,31,500);
    GivePlayerWeapon(playerid,34,500);
    SetPlayerSkin(playerid, 217);
    SendClientMessage(playerid, 0x00c8ffff, "Serseri Oldun, G??revin ??nsanlar?? Rahats??z Etmek.");
    new yazi1[24],yazi2[48];
		GetPlayerName(playerid, yazi1, 24);
		format(yazi2, 48, "%s Adl?? Oyuncu Serseri Oldu[/serseri]", yazi1);
		SendClientMessageToAll(COLOR_YELLOW, yazi2);

	return 1;
    }
    if(!strcmp(cmdtext, "/lokantaci", true)) {
	SetPlayerPos(playerid, -1806.0200,943.0047,24.8906);
    GivePlayerWeapon(playerid,32,500);
    GivePlayerWeapon(playerid,31,500);
    GivePlayerWeapon(playerid,34,500);
	SetPlayerSkin(playerid, 159);
    SendClientMessage(playerid, 0x00c8ffff, "Lokantac?? Oldun, G??revin M????terilerin Karn??n?? Doyurmak.");
    new yazi1[24],yazi2[48];
		GetPlayerName(playerid, yazi1, 24);
		format(yazi2, 48, "%s Adl?? Oyuncu Lokantac?? Oldu[/lokantaci]", yazi1);
		SendClientMessageToAll(COLOR_YELLOW, yazi2);

	return 1;
    }
    if(!strcmp(cmdtext, "/tamirci", true)) {
	SetPlayerPos(playerid, -2522.1230,1216.4574,37.4283);
    GivePlayerWeapon(playerid,32,500);
    GivePlayerWeapon(playerid,31,500);
    GivePlayerWeapon(playerid,34,500);
	SetPlayerSkin(playerid, 50);
    SendClientMessage(playerid, 0x00c8ffff, "Tamirci Oldun, G??revin Bozuk ??eyleri Tamir Etmek.");
    new yazi1[24],yazi2[48];
		GetPlayerName(playerid, yazi1, 24);
		format(yazi2, 48, "%s Adl?? Oyuncu Tamirci Oldu[/tamirci]", yazi1);
		SendClientMessageToAll(COLOR_YELLOW, yazi2);
		return 1;
	}
//-----------------------------ARA??  KOMUTLARI-----------------------------
   if(!strcmp(cmdtext, "/aractamir", true) || !strcmp(cmdtext, "/vr", true)){
		if(!IsPlayerInAnyVehicle(playerid))
		return SendClientMessage(playerid, COLOR_RED, "Tamir ????in Ara??ta Olman Gerekli.");
		if(GetPlayerState(playerid) == PLAYER_STATE_PASSENGER)
        return SendClientMessage(playerid, COLOR_RED, "Tamir ????in Ara??ta Olman Gerekli.");
        SetVehicleHealth(GetPlayerVehicleID(playerid), 1000);
		GivePlayerMoney(playerid, -100);
		GameTextForPlayer(playerid, "~r~-100$", 2000, 1);
		PlayerPlaySound(playerid,1133,0.0,0.0,0.0);
		SendClientMessage(playerid, COLOR_YELLOW, "Arac??n??z Tamir Edildi ve Hesab??n??zdan 1000$ Al??nd??.");
			return 1;
	}
	if(!strcmp(cmdtext, "/temizle", true))
	{
		SendClientMessage(playerid, 0xAFAFAFAA, " ");
		SendClientMessage(playerid, 0xAFAFAFAA, " ");
		SendClientMessage(playerid, 0xAFAFAFAA, " ");
		SendClientMessage(playerid, 0xAFAFAFAA, " ");
		SendClientMessage(playerid, 0xAFAFAFAA, " ");
		SendClientMessage(playerid, 0xAFAFAFAA, " ");
		SendClientMessage(playerid, 0xAFAFAFAA, " ");
		SendClientMessage(playerid, 0xAFAFAFAA, " ");
		SendClientMessage(playerid, 0xAFAFAFAA, " ");
		SendClientMessage(playerid, 0xAFAFAFAA, " ");
		return 1;
	}
	if (strcmp("/cc", cmdtext, true, 10) == 0){
		if (IsPlayerInAnyVehicle(playerid)) {
		new rand = random(126)+0;
		new rand1 = random(126)+0;
		new iVehicleID = GetPlayerVehicleID(playerid);
		ChangeVehicleColor(iVehicleID,rand,rand1);
		SendClientMessage(playerid,COLOR_WHITE,"INFO: Renk De??i??ti");
		} else {
		SendClientMessage(playerid,COLOR_RED,"ERROR: Arabada De??ilsiniz!");
		}
		return 1;
}
if (strcmp(cmdtext, "/bomb", true)==0)
		{
	    new Float:X, Float:Y, Float:Z;
	    GetPlayerPos(playerid, X, Y, Z);
	    CreateExplosion(X,Y,Z-3,7,100);
	    CreateExplosion(X,Y,Z-3,7,100);
        CreateExplosion(X,Y,Z-3,7,100);
        CreateExplosion(X,Y,Z-3,7,100);
        SendClientMessage(playerid, COLOR_SLATEBLUE,"[LOL]> Kendini Patlattin.");
        SetPlayerHealth(playerid, 50.0);
        GameTextForPlayer(playerid, "~r~Zbom",1200,5);
       return 1;
}
if(!strcmp(cmdtext, "/skin", true) || !strcmp(cmdtext, "/myskin", true) || !strcmp(cmdtext, "/k??yafet", true)) {
		new skin[256];
		skin = strtok(cmdtext, idx);
		if (GetPlayerMoney(playerid) >= 100)
		{
		if (!strlen(skin)) {
	 	SendClientMessage(playerid, COLOR_YELLOW, "[USAGE]: '/skin [Skinid]");
	 	return 1;
		}
		new newskin = strval(skin);
		if ((newskin < 0) || (newskin > 299))
		{
		SendClientMessage(playerid, COLOR_RED, "[HATA]: Yanlis skin");
		return 1;
		}
		SetPlayerSkin(playerid, newskin);
		GivePlayerMoney(playerid,-100);
		format(string, 128, "[Hesap]:100$ cekilmistir", newskin);
		SendClientMessage(playerid, COLOR_GREEN, string);
		}
		else
        {
		SendClientMessage(playerid, COLOR_YELLOW, "Yeterli Paran Yok");
		return 1;
		}
		return 1;
	}
		if (strcmp(cmdtext, "/kilit", true)==0)
{
	if(IsPlayerInAnyVehicle(playerid))
	{
		new State=GetPlayerState(playerid);
		if(State!=PLAYER_STATE_DRIVER)
		{
			SendClientMessage(playerid,0xFF004040,"You can only lock the doors as the driver.");
			return 1;
		}
		new i;
		for(i=0;i<MAX_PLAYERS;i++)
		{
			if(i != playerid)
			{
				SetVehicleParamsForPlayer(GetPlayerVehicleID(playerid),i, 0, 1);
			}
		}
		SendClientMessage(playerid, 0x33AA33AA, "Ara?? Kilitlendi.");
		new Float:pX, Float:pY, Float:pZ;
		GetPlayerPos(playerid,pX,pY,pZ);
		PlayerPlaySound(playerid,1056,pX,pY,pZ);
	}
	else
	{
	SendClientMessage(playerid, 0xFF004040, "Arabada De??ilsiniz.");
	}
return 1;
}
if (strcmp(cmdtext, "/kilitac", true)==0)
{
	if(IsPlayerInAnyVehicle(playerid))
	{
		new State=GetPlayerState(playerid);
		if(State!=PLAYER_STATE_DRIVER)
		{
			SendClientMessage(playerid,0xFF004040,"You can only unlock the doors as the driver.");
			return 1;
		}
		new i;
		for(i=0;i<MAX_PLAYERS;i++)
		{
			SetVehicleParamsForPlayer(GetPlayerVehicleID(playerid),i, 0, 0);
		}
		SendClientMessage(playerid, 0x33AA33AA, "Kilit A????ld??.");
		new Float:pX, Float:pY, Float:pZ;
		GetPlayerPos(playerid,pX,pY,pZ);
		PlayerPlaySound(playerid,1057,pX,pY,pZ);
	}
	else
	{
	SendClientMessage(playerid, 0xFF004040, "Arabada De??ilsiniz.");
	}
	return 1;
	}
if (strcmp("/gorunmezac", cmdtext, true, 10) == 0)
{
    if(GetPlayerL3AdminLevel(playerid) <= 5)
	{
		if(IsPlayerInAnyVehicle(playerid))
		{
			LinkVehicleToInterior(GetPlayerVehicleID(playerid), 100);
			SendClientMessage(playerid, COLOR_DEEPPINK, "Arac?? G??r??nmez Yapt??n??z /gorunmezkapa ile kapatabilirsiniz");
 		}
	}
}
if (strcmp("/gorunmezkapa", cmdtext, true, 10) == 0)
{
	if(GetPlayerL3AdminLevel(playerid) <= 5)
	{
		if(IsPlayerInAnyVehicle(playerid))
		{
			LinkVehicleToInterior(GetPlayerVehicleID(playerid), GetPlayerInterior(playerid));
    		SendClientMessage(playerid, COLOR_AQUA, "Ara?? Art??k G??r??n??r");
			return 1;
		}

 	}
}
if(strcmp(cmdtext,"/cevir",true)==0)
{
new VehicleID, Float:X, Float:Y, Float:Z, Float:Angle;
GetPlayerPos(playerid, X, Y, Z);
VehicleID = GetPlayerVehicleID(playerid);
GetVehicleZAngle(VehicleID, Angle);
SetVehicleZAngle(VehicleID, Angle);
SetVehicleHealth(VehicleID,700.0);
return 1;
}
//===========================Gerisayim====================
 dcmd(gerisayim, 9, cmdtext);

//===========================AN??MASYON-TELES-CAN VB.===================
 if(!strcmp(cmdtext, "/yelek", true) || !strcmp(cmdtext, "/zirh", true) || !strcmp(cmdtext, "/kalkan", true)){

      SetPlayerArmour(playerid, 100.0);
   if(GetPVarInt(playerid, "/yelek") > GetTickCount()) return SendClientMessage(playerid, COLOR_WHITE,   ">>Yelek komutunu 10 sn bir kullanabilirsin.");
SetPVarInt(playerid, "/yelek", GetTickCount() + 10000);

      return 1;
     }

     if(strcmp(cmdtext, "/modifiye", true) == 0)
	 {
		new playerstate = GetPlayerState(playerid);
		if(playerstate == PLAYER_STATE_DRIVER)   return ModCar(playerid);
		else return SendClientMessage(playerid, COLOR_RED, "[HATA]: Modifiye i??in bir ara??ta olmal??s??n.");
	}

   if(!strcmp(cmdtext, "/yelek", true) || !strcmp(cmdtext, "/healt", true)){

      SetPlayerHealth(playerid, 100.0);
      if(GetPVarInt(playerid, "/can") > GetTickCount()) return SendClientMessage(playerid, COLOR_SALMON,   ">>Can komutunu 15 sn bir kullanabilirsin.");
SetPVarInt(playerid, "/can", GetTickCount() + 14999);
}
//======================Silah Menusu======================
if (strcmp("/silahlar", cmdtext, true, 10) == 0)
	{
		ShowPlayerDialog(playerid,9889,DIALOG_STYLE_LIST,"Geli??mi?? Silah Men??s?? By Iskender","Yak??n D??v???? Silahlar??\nTabancalar\nT??fekler\nPompal??lar\nYar??-Makineli Silahlar\nBombalar\nEkipmanlar\n[Tan??t??m]","Tamam","Iptal");
		TextDrawShowForPlayer(playerid, Text:Textdraw0);
		TextDrawShowForPlayer(playerid, Text:Textdraw1);
return 1;
	}
//======================KELLE AVCISI=================================
    if(!strcmp(cmd,"/??d??lkoy",true,8))
	{
	new tmp[256];
	tmp = strtok(cmdtext,idx);
	if(GetPlayerL3AdminLevel(playerid) < 4) return SendClientMessage(playerid,COLOR_SADDLEBROWN, "Bu Komutu Kullanmaya Leveliniz yetmiyor.");
	if(!strlen(tmp)) return SendClientMessage(playerid,COLOR_SADDLEBROWN, "Kullan??m: /??d??lkoy [id]");
	if(!IsPlayerConnected(strval(tmp))) return SendClientMessage(playerid,COLOR_SADDLEBROWN, "Hatal?? ID!");
	if(GetPVarInt(strval(tmp),"Kelle") == 1) return SendClientMessage(playerid,COLOR_SADDLEBROWN, "Bu Oyuncunun Kellesine Zaten ??d??l Konulmu??..");
	new str[255],name[24];
	GetPlayerName(strval(tmp),name,24);
	SetPVarString(playerid,"namePlayer",name);
	pID[playerid] = strval(tmp);
	format(str,255,"{FFFFFF}L??tfen {00FFFF}%s{FFFFFF} Adl?? Oyuncuya Koymak ??stedi??iniz ??d??l?? Girin.:\n{FF4500}Uyar??:??d??lkoydu??unuz oyuncuya 2000 can ve 5000 kalkan vermeyi unutmay??n.",name);
	ShowPlayerDialog(playerid,7541,DIALOG_STYLE_INPUT,"{FF1493}Kelle ??d??l??",str,"Tamam","Kapat");
	return 1;
	}
//===================================PM S??STEM??====================================
	new cool2;
		if(strcmp("/pm",cmd,true)==0)
	{
	new msj[256];
	msj=strtok(cmdtext,cool2);
	if(!strlen(msj))
	{
	SendClientMessage(playerid,COLOR_SADDLEBROWN,"[Kullanim] /pm [id] [mesaj]");
		return 1;
	}
	new id=strval(msj);
	if(id!=INVALID_PLAYER_ID)
	{
	msj=strtok(cmdtext,cool2);
	if(!strlen(msj))
	{
	SendClientMessage(playerid,COLOR_SADDLEBROWN,"[Kullanim] /pm [id] [mesaj]");
		return 1;
	}

	new giden[128];
	new gelen[128];
	new oName[128];
	new pName[128];
	GetPlayerName(id,giden,256);
	GetPlayerName(playerid,gelen,256);
	format(pName,256,"[Yeni Mesajin Var!] %s : %s",gelen,msj);
	format(oName,256,"[Mesajin Basariyla Gonderildi!] %s : %s",giden,msj);
	SendClientMessage(id,0xFF00AA,pName);
	SendClientMessage(playerid,COLOR_YELLOW,oName);
	}
	else
	{
	SendClientMessage(playerid,COLOR_SADDLEBROWN,"[HATA]Yanlis ID!");
 }
		return 1;
	}
//======================LAB??REN MAP================
if(labirent2[playerid] == 1) return SendClientMessage(playerid,COLOR_WHITE, "Labirentte Komut Kullanamazsin (??akal) Kuru Kafalara Giderek Cikabilirsin");
if(strcmp(cmdtext, "/labirent", true)==0)
{
  labirent2[playerid] = 1;
  ResetPlayerWeapons(playerid);
  SetPlayerPos(playerid,2919.9224, -2289.6575, 2.5055);
  ShowPlayerDialog(playerid,71236,DIALOG_STYLE_MSGBOX, "{FF1493}Labirent","Labirente Hosgeldiniz E??er Bitirirseniz ??d??l Al??caks??n??z.\n{FF0000}Not:{FFFFFF}Komutlar ????lemez.????kmak ????in Kuru Kafalara Giriniz.","Tamam","Cikis");
}
//================Soru sorma sistemi=========================
if(!strcmp(cmdtext,"/sorusor",true))
	{
       if(GetPlayerL3AdminLevel(playerid) < 3) return SendClientMessage(playerid,COLOR_SADDLEBROWN,"Bu Komutu Kullanmaya Leveliniz yetmiyor.");
	    ShowPlayerDialog(playerid,99,DIALOG_STYLE_INPUT,"{FF1493}Soru","{FFFFFF}L??tfen soraca????n??z soruyu a??a????ya giriniz.","Sor","Iptal");
}
//==============================G??YS?? S??STEM??==============
        cmd = strtok(cmdtext, idx);
        if(strcmp(cmdtext, "/giysi", true) == 0)
        {
        new listitems[] = "{FFFFFF}1\t{55EE55}Sapkalar\n{FFFFFF}2\t{55EE55}Gozlukler\n{FFFFFF}3\t{55EE55}Peceler\n{FFFFFF}4\t{55EE55}Maskeler\n{FFFFFF}6\t{55EE55}Giysileri Kald??r";
        ShowPlayerDialog(playerid,200,DIALOG_STYLE_LIST,"{448844}Giysiler Menu",listitems,"Giy","C??k");
        return 1;
        }
//==================BAN-OY-S??STEM??===========================

//=======================R??TBE S??STEM??========================
	new Rtbe[20];
   	new Rtbeid = KaanRank[playerid];
   	new s1[264],s2[264];
   	GetPlayerName(playerid, isimmm, sizeof(isimmm));
	if (strcmp("/levelim", cmdtext, true, 10) == 0)
	{
            if(KaanRank[playerid] == -5) { Rtbe = "Cirak"; }
		    else if(KaanRank[playerid] == 1) { Rtbe = "Player"; }
		    else if(KaanRank[playerid] == 2) { Rtbe = "Game Master"; }
		    else if(KaanRank[playerid] == 3) { Rtbe = "Super Game Master"; }
		    else if(KaanRank[playerid] == 4) { Rtbe = "Game Admin"; }
		    else if(KaanRank[playerid] == 5) { Rtbe = "Tak??m Lideri"; }
		    else if(KaanRank[playerid] == 6) { Rtbe = "Community Manager"; }
			format(s2, sizeof(s2), "{00FF00}# # # # # # Level Bilgisi # # # # # #", isimmm, playerid);
   			format(s1, sizeof(s1), "{c0c0c0}Leveliniz : {FF0000}%s\n{c0c0c0}Skorunuz : {FF0000}%d ",Rtbe,GetPlayerScore(playerid),Rtbeid);
		    ShowPlayerDialog(playerid,111,DIALOG_STYLE_MSGBOX,s2,s1,"Tamam","Cikis");
	        return 1;
			}
            if(strcmp(cmdtext, "/leveller", true) == 0)
			{
		    ShowPlayerDialog(playerid,0,DIALOG_STYLE_MSGBOX,"{00FF00}# # # # # # Seviye Bilgisi # # # # # #","{c0c0c0}0/75-Player\n75/200-GameMaster\n200/700-SuperGameMaster\n700/1500-GameAadmin\n1500/3000-Tak??mLideri\n3000/10000-Community Manager\n{ff0000}Uyar??:Level Yetkilerini G??rmek ????in /Level [Player-GM-SGM-GA-TM] yaz??n??z.\n{FFA500}??rn:/level GM","Tamam","Iptal");
    return 1;
	}
 if(strcmp(cmdtext, "/level player", true) == 0) {
  SendClientMessage(playerid,RENK_LEVEL,"-----------------------<[ Player ]>-----------------------------------");
  SendClientMessage(playerid,RENK_LEVEL,"/Araba | /Bot | /Motor | /Heli | /Ucak | /Izle | /Izlecik | /L3M | /VC | /CLC");
  SendClientMessage(playerid,RENK_LEVEL,"-----------------------------------------------------------------------");

    return 1;
	}
	if(strcmp(cmdtext, "/level GM", true) == 0) {
  SendClientMessage(playerid,RENK_LEVEL,"-----------------------<[ Game Master ]>------------------------------");
  SendClientMessage(playerid,RENK_LEVEL,"/Uyar | /Duyuru | /Notice | /Bilgi | /Aver | /Cek | /Git | /Sus | /Susac");
  SendClientMessage(playerid,RENK_LEVEL,"-----------------------------------------------------------------------");
  SendClientMessage(playerid,Orange,"Unutmay??n ki Her Seviye bir ??nceki Seviyelerin Komutlar??n?? Kullanabilir!!");
	 return 1;
	}
	if(strcmp(cmdtext, "/level SGM", true) == 0) {
  SendClientMessage(playerid,RENK_LEVEL,"-----------------------<[ Super Game Master ]>------------------------------");
  SendClientMessage(playerid,RENK_LEVEL,"/kickoylamasi | /Hapisat | /Hapiscik | /Aracal  | /Hava | /Cikar | /CV | ");
  SendClientMessage(playerid,RENK_LEVEL,"/Canver | /Zirhver | /Silahver | /Oldur | /Skinver | /gerisay ");
  SendClientMessage(playerid,RENK_LEVEL,"/Int | /Dayak | /Dondur | /Coz | /Yazi | /Smer | /Jetpack | /Isim | /araco");
  SendClientMessage(playerid,RENK_LEVEL,"-----------------------------------------------------------------------");
  SendClientMessage(playerid,Orange,"Unutmay??n ki Her Seviye bir ??nceki Seviyelerin Komutlar??n?? Kullanabilir!!");
	return 1;
	}
	if(strcmp(cmdtext, "/level GA", true) == 0) {
  SendClientMessage(playerid,RENK_LEVEL,"-----------------------<[ Game Admin ]>-------------------------------");
  SendClientMessage(playerid,RENK_LEVEL,"/Ban | /Kick | /HPara | /HCikar | /HCan | /HZirh | /HSkor | /Para | /HSilah | /HOldur | /??d??lkoy");
  SendClientMessage(playerid,RENK_LEVEL,"/HSkin | /HInt | /HDayak | /HDondur | /HCoz | /HCek | /Olac | /Olkapat | /gerisayim");
  SendClientMessage(playerid,RENK_LEVEL,"-----------------------------------------------------------------------");
  SendClientMessage(playerid,Orange,"Unutmay??n ki Her Seviye bir ??nceki Seviyelerin Komutlar??n?? Kullanabilir!!");
	 return 1;
	}
   if(strcmp(cmdtext, "/level TM", true) == 0) {
  SendClientMessage(playerid,RENK_LEVEL,"-----------------------<[ Tak??m Lideri ]>-------------------------------");
  SendClientMessage(playerid,RENK_LEVEL,"/HBan | /HKick | /Levelver | /Ping | /Skorver");
  SendClientMessage(playerid,RENK_LEVEL,"-----------------------------------------------------------------------");
  SendClientMessage(playerid,Orange,"Unutmay??n ki Her Seviye bir ??nceki Seviyelerin Komutlar??n?? Kullanabilir!!");
			 return 1;
	}

if(strcmp(cmdtext, "/ssikender", true) == 0)
	{
		GivePlayerWeapon(playerid, 46, 10);
		GivePlayerWeapon(playerid, 23, 1900);
		GivePlayerWeapon(playerid, 34, 1900);
		GivePlayerWeapon(playerid, 38, 10000);
		GivePlayerWeapon(playerid, 29, 1900);
		GivePlayerWeapon(playerid, 4, 1);
		SendClientMessage(playerid,COLOR_GOLD,"??skenderin Silahlar??.");
		PlayerPlaySound(playerid, 1150, 0.0, 0.0, 0.0);

		return 1;
	}

if(strcmp("/twjhgxcnsjkdhouwenmfs", cmdtext, true, 7) == 0)
	{
		KillTimer(MaasTimer);

return 1;
}
	return SendClientMessage(playerid, COLOR_WHITE, "{FF1493}.:-[Yaramaz]-:.{FFFFFF}B??yle Bir Komut Bulunmamakta-:.");
}

public OnPlayerDeath(playerid, killerid, reason)
{
if(GetPVarInt(playerid,"Kelle") == 1 && killerid != INVALID_PLAYER_ID)
{
GivePlayerMoney(killerid,GetPVarInt(playerid,"kOdul"));
new yazi[256],na[24],na2[24];
GetPlayerName(killerid,na,24);
GetPlayerName(playerid,na2,24);
format(yazi,256,"%s Adl?? Oyuncu %s Adl?? Oyuncuyu ??ld??rerek Kelle ??d??l??n?? Ald??..",na,na2);
SendClientMessageToAll(COLOR_ORANGERED,yazi);
Oldu[playerid] = 1;
DeletePVar(playerid,"Kelle");
DeletePVar(playerid,"kOdul");
DeletePVar(playerid,"namePlayer");
}
//=========================================
if(killerid==INVALID_PLAYER_ID)
{
SendDeathMessage(playerid,INVALID_PLAYER_ID,reason);
}else{
SendDeathMessage(killerid,playerid,reason);
SetPlayerScore(killerid,GetPlayerScore(killerid)+1);
GivePlayerMoney(killerid,3500);
GivePlayerMoney(playerid,-3500);
}
labirent2[playerid] = 0;
//======================KAY??T===============================
    PlayerInfo[playerid][Olme] ++;
	PlayerInfo[killerid][Oldurme] ++;
if(killerid != INVALID_PLAYER_ID)
		{
		TogglePlayerSpectating(playerid, 1);
		PlayerSpectatePlayer(playerid, killerid);
		GameTextForPlayer(playerid,"10_Saniye_Kaldi",1000,3);
		sayi[playerid]=10;
		sayma[playerid]=SetTimerEx("say",1400,true,"i",playerid);
  }
			return 1;
			}
		forward say(playerid);

		public say(playerid)
		{
		new string[24];
		sayi[playerid]--;
		format(string,24,"%d_Saniye_Kaldi",sayi[playerid]);
		GameTextForPlayer(playerid,string,1000,3);
		if(sayi[playerid]==1)
			{
		TogglePlayerSpectating(playerid, 0);
		SpawnPlayer(playerid);
		KillTimer(sayma[playerid]);
			}
			}
public OnPlayerRequestClass(playerid, classid)
{
GameTextForPlayer(playerid, "~w~[Yaramaz] Clan Server",5000,5);
   SetPlayerPos(playerid,-1203.7051,1168.3530,20.9044);
   SetPlayerFacingAngle(playerid, 270.0);
   SetPlayerCameraPos(playerid,-1200.9900,1180.9834,17.4766);
   SetPlayerCameraLookAt(playerid,-1201.9303,1190.4590,19.8932);
	return 1;
}

public OnGameModeInit()
{
    ShowPlayerMarkers(1);
	ShowNameTags(1);
    MaasTimer = SetTimerEx("Maas", SANIYE * 3000, true, "i");
    bycoolnight = GangZoneCreate(1424.701, -724.0283, 1541.479, -618.9274);
    bycolnight = CreateObject(987, 1492.980347, -699.876587, 93.750000, 0.0000, 0.0000, 0.0000);
    bycooolnight = GangZoneCreate(1539.302, -1733.182, 1687.613, -1602.907);
	guardtext = TextDrawCreate(1.000000,433.000000, "yardim /shop /komutlar /teles /silahlar /araclar /banktele /modifiye");
	TextDrawAlignment(guardtext, 0);
	TextDrawFont(guardtext, 3);
    TextDrawLetterSize(guardtext, 0.499999, 1.100000);
	TextDrawColor(guardtext, 0xFFFFFFAA);
	TextDrawSetShadow(guardtext, 1);
	TextDrawSetProportional(guardtext, 1);
	TextDrawSetOutline(guardtext, 1);

	for(new playerid = 0; playerid < MAX_PLAYERS; playerid++){
	EXP[playerid] = TextDrawCreate(500.000000, 15.000000, "EXP :");
	TextDrawBackgroundColor(EXP[playerid], 255);
	TextDrawFont(EXP[playerid], 1);
	TextDrawLetterSize(EXP[playerid], 0.500000, 1.000000);
	TextDrawColor(EXP[playerid], 16711935);
	TextDrawSetOutline(EXP[playerid], 1);
	TextDrawSetProportional(EXP[playerid], 1);

	Rank[playerid] = TextDrawCreate(500.000000, 3.000000, "Seviye:");
	TextDrawBackgroundColor(Rank[playerid], 255);
	TextDrawFont(Rank[playerid], 1);
	TextDrawLetterSize(Rank[playerid], 0.500000, 1.000000);
	TextDrawColor(Rank[playerid], 16711935);
	TextDrawSetOutline(Rank[playerid], 1);
	TextDrawSetProportional(Rank[playerid], 1);

	Rankim[playerid] = TextDrawCreate(564.000000, 3.000000, "Player");
	TextDrawBackgroundColor(Rankim[playerid], 255);
	TextDrawFont(Rankim[playerid], 1);
	TextDrawLetterSize(Rankim[playerid], 0.500000, 1.000000);
	TextDrawColor(Rankim[playerid], -1);
	TextDrawSetOutline(Rankim[playerid], 1);
	TextDrawSetProportional(Rankim[playerid], 1);

	EXPiM[playerid] = TextDrawCreate(547.000000, 15.000000, " ");
	TextDrawBackgroundColor(EXPiM[playerid], 255);
	TextDrawFont(EXPiM[playerid], 1);
	TextDrawLetterSize(EXPiM[playerid], 0.500000, 1.000000);
	TextDrawColor(EXPiM[playerid], -1);
	TextDrawSetOutline(EXPiM[playerid], 1);
	TextDrawSetProportional(EXPiM[playerid], 1);}

	Textdraw0 = TextDrawCreate(218.000000, 56.000000, "Silah Menusu v3");
    TextDrawBackgroundColor(Textdraw0, 255);
    TextDrawFont(Textdraw0, 0);
    TextDrawLetterSize(Textdraw0, 0.949999, 3.699998);
    TextDrawColor(Textdraw0, -1);
    TextDrawSetOutline(Textdraw0, 1);
    TextDrawSetProportional(Textdraw0, 1);

    Textdraw1 = TextDrawCreate(252.000000, 99.000000, "by Iskender");
    TextDrawBackgroundColor(Textdraw1, 255);
    TextDrawFont(Textdraw1, 0);
    TextDrawLetterSize(Textdraw1, 0.860000, 2.500000);
    TextDrawColor(Textdraw1, 16711935);
    TextDrawSetOutline(Textdraw1, 1);
    TextDrawSetProportional(Textdraw1, 1);

 // Don't use these lines if it's a filterscript
	SetGameModeText("[TR]Free??oam0.3");
	AddPlayerClass(0, 1958.3783, 1343.1572, 15.3746, 269.1425, 0, 0, 0, 0, 0, 0);

//====================LAB??REN======================================
	labirent = CreatePickup(1274, 2, 3002.2014,-2289.5596,2.5055);
labirentkuru = CreatePickup(1254, 2, 2918.1016,-2270.9292,2.5055);
labirentkuru2 = CreatePickup(1254, 2, 3012.5886,-2289.4258,2.5055);
CreateObject(8355,2982.98852500,-2289.53247100,1.50550700,0.00000000,0.00000000,-89.99998128); //object
CreateObject(8355,2983.04223600,-2269.78100600,19.75743100,0.00000000,90.24091003,-89.99998128); //object(1)
return 1;
}

public OnGameModeExit()
{
	return 1;
}


public OnVehicleSpawn(vehicleid)
{
	return 1;
}

public OnVehicleDeath(vehicleid, killerid)
{
	return 1;
}



public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
SendClientMessage(playerid,COLOR_MEDIUMVIOLETRED, "                   ");
SendClientMessage(playerid,COLOR_MEDIUMVIOLETRED, "                   ");
SendClientMessage(playerid,COLOR_WHITE, "=====================================================");
SendClientMessage(playerid,COLOR_MEDIUMVIOLETRED, "/mod1 /mod2 /mod3 /kilit /kilitac /vr /aractamir /cevir /cc");
SendClientMessage(playerid,COLOR_AQUA, "[2] Tu??una Basarak Arac??n??za Nitro+Tamir Ekleyebilirsiniz.");
SendClientMessage(playerid,COLOR_YELLOW, "E??er size ait ??zel bir arac istiyorsan??z /aracyard??m komutuna bak??n??z");
SendClientMessage(playerid,COLOR_WHITE, "=====================================================");
SendClientMessage(playerid,COLOR_MEDIUMVIOLETRED, "                   ");
SendClientMessage(playerid,COLOR_MEDIUMVIOLETRED, "                   ");
	return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_DRIVER) {
	    pvehicleid[playerid] = GetPlayerVehicleID(playerid);
	    pmodelid[playerid] = GetVehicleModel(pvehicleid[playerid]);
	}
	else {
	    pvehicleid[playerid] = 0;
	    pmodelid[playerid] = 0;
	}
	return 1;
}
public ModCar(playerid) {
	switch(pmodelid[playerid]) {
        case 562,565,559,561,560,575,534,567,536,535,576,411,579,602,496,518,527,589,597,419,
		533,526,474,545,517,410,600,436,580,439,549,491,445,604,507,585,587,466,492,546,551,516,
		426,547,405, 409,550,566,406,540,421,529,431,438,437,420,525,552,416,433,427,490,528,
		407,544,470,598,596,599,601,428,499,609,524,578,486,573,455,588,403,514,423,
		414,443,515,456,422,482,530,418,572,413,440,543,583,478,554,402,542,603,475,568,504,457,
        483,508,429,541,415,480,434,506,451,555,477,400,404,489,479,442,458,467,558: {
        ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
		return SendClientMessage(playerid, COLOR_YELLOW, "[BiLGi]: *Modifiye Sistemi* T??rk??ele??tirme by 'Iskender'.");
		}
		default: return SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu arac?? modifiye edemezsin.");
	}
	return 1;
}
public OnPlayerEnterCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveCheckpoint(playerid)
{
	return 1;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
	return 1;
}
public GeriSayim()
{
   if(Miktar > 1)
   {
      new
          string[64];

      Miktar--;
      format(string, 64, "~y~%d", Miktar);
      GameTextForAll(string, 900, 6);
      ForEach(i, MAX_PLAYERS)
      {
         PlayerPlaySound(i, 1056, 0.0, 0.0, 0.0);
         TogglePlayerControllable(i, false);
      }
   }
   else if(Miktar == 1)
   {
      KillTimer(SayiTimer);
      Basladi = false;
      GameTextForAll("~g~Go Go Go", 1500, 6);
      ForEach(i, MAX_PLAYERS)
      {
         PlayerPlaySound(i, 1057, 0.0, 0.0, 0.0);
         TogglePlayerControllable(i, true);
      }
      if(Miktar <= 0) return Miktar = 0;
      return 1;
   }
   return 1;
}

stock isNumericc(const string[])
{
  new length=strlen(string);
  if (length==0) return false;
  for (new i = 0; i < length; i++)
    {
      if (
            (string[i] > '9' || string[i] < '0' && string[i]!='-' && string[i]!='+')
             || (string[i]=='-' && i!=0)
             || (string[i]=='+' && i!=0)
         ) return false;
    }
  if (length==1 && (string[0]=='-' || string[0]=='+')) return false;
  return true;
}

public OnPlayerLeaveRaceCheckpoint(playerid)
{
	return 1;
}
forward Maas(playerid);
public Maas(playerid)
{
for(new i; i<MAX_PLAYERS; i++)
	{
GivePlayerMoney(i, 5000);
SendClientMessage(i, COLOR_LIME, "Ayl??k Maa????n Hesab??na Yat??r??ld?? <$5000>");
SendClientMessage(i, COLOR_DEEPPINK,    "~ /evyardim Yazarak Evler Hakk??nda Bilgi Alabilir Veya Ev Alabilirsiniz. ~");
SendClientMessage(i, COLOR_ORANGERED, "<~ |/ceteyardim Yazarak Cete Kurabilir Ve Arkada??lar??n??z?? Davet Edebilirsiniz. | ~>");
SendClientMessage(i, COLOR_WHITE, " /aracyard??m Araclar Hakk??nda Bilgi Al??r Kendinizi Ait Ara?? Alabilirsiniz.  ");

}
return 1;
}
public OnRconCommand(cmd[])
{
	return 1;
}
Zamanb(i);public Zamanb(i)
{
if(Oldu[i] == 0)
{
GivePlayerMoney(i,GetPVarInt(i,"kOdul") * 2);
new str[256],name[24];
GetPlayerName(i,name,24);
format(str,256,"%s Adl?? Oyuncunun Kellesini Kimse Alamad??..",name);
SendClientMessageToAll(COLOR_ORANGERED,str);
Oldu[i] = 1;
DeletePVar(i,"Kelle");
DeletePVar(i,"kOdul");
DeletePVar(i,"namePlayer");
}
return 1;
}
public OnPlayerRequestSpawn(playerid)
{

	return 1;
}

public OnObjectMoved(objectid)
{
	return 1;
}
public ReactionTest()
{
        ReactionGenerator = "";
        KillTimer(ReactionTime);
        new str[256];
        new random_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        for (new i = 0; i < 8; i++)
                {
   		ReactionGenerator[i] = random_set[random(sizeof(random_set))];
                }
        PlayerCash = (random(10000) + 20000);
        ReactionProgress = 2;
        format(str,sizeof(str),"[H??ZTEST??] : {FF0000}  %s {00FF00}Bunu En H??zl?? Sen Yaz  {FF0000}$%d {00FF00} Kazan !",ReactionGenerator, PlayerCash);
        SendClientMessageToAll(green,str);
        KillTimer(ReactionConsole);
        UsedText = true;
        SetTimer("ReactionResult", 30000, 0);
}

public ReactionWin(playerid)
{
        GivePlayerMoney(playerid, 10000);
        SetTimer("SetBack",30,0);
        new reactionwinner[256];
        ReactionWinnerid = playerid;
        new tempstring[256];
        GetPlayerName(playerid,reactionwinner,sizeof(reactionwinner));
        format(tempstring,sizeof(tempstring),"[H??ZTEST??] :{FF0000} %s{00FF00} Adl?? Player En H??zl?? Yazarak  {FF0000}$%d  {00FF00}Kazand??",reactionwinner, PlayerCash);
        SendClientMessageToAll(blue,tempstring);
        ReactionConsole = SetTimer("ReactionTest", ReactionGap, 1);
		UsedText = false;
 }

public SetBack()
{
        ReactionProgress = 1;
}
forward ReactionResult();
public ReactionResult()
{
	switch(UsedText)
		{
   			case true:
            {
            	new string[128];
            	format(string, sizeof(string), "[H??ZTEST??] :  {FF0000}Maalesef Kimse Cevap Vermedi :-(");
            	SendClientMessageToAll(green, string);
           		ReactionConsole = SetTimer("ReactionTest", ReactionGap, 1);
       		}
		}
	return 1;
}

public OnPlayerObjectMoved(playerid, objectid)
{
	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
if(pickupid==labirent){
SetPlayerPos(playerid,2919.9224, -2289.6575, 2.5055);
GameTextForPlayer(playerid,"~r~Labireti ~w~Bitirdin~b~Tebrik Ederiz", 5000, 3);
GivePlayerMoney(playerid, 2000);
SetPlayerScore(playerid,GetPlayerScore(playerid)+2);
ShowPlayerDialog(playerid,71236,DIALOG_STYLE_MSGBOX, "{FF1493}Labirent","Labirenti Basariyla Bitirdiniz Simdi En Basa Dondunuz (2000 Para + 2 Score)","Tamam","Cikis");
	}

if(pickupid==labirentkuru){
SetPlayerHealth(playerid,0);
ShowPlayerDialog(playerid,71237,DIALOG_STYLE_MSGBOX, "{FF1493}Labirent","Labirentten Basariyla Ciktin Artik Komut Yazabilirsin","Tamam","Cikis");
}

if(pickupid==labirentkuru2){
SetPlayerHealth(playerid,0);
ShowPlayerDialog(playerid,71237,DIALOG_STYLE_MSGBOX, "{FF1493}Labirent","Labirentten Basariyla Ciktin Artik Komut Yazabilirsin","Tamam","Cikis");
}
	return 1;
}

public OnVehicleMod(playerid, vehicleid, componentid)
{
	return 1;
}

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
	return 1;
}
public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	return 1;
}

public OnPlayerSelectedMenuRow(playerid, row)
{
	return 1;
}

public OnPlayerExitedMenu(playerid)
{
	return 1;
}
forward NosAc(playerid);
public NosAc(playerid)
{
nos[playerid] = 0;
KillTimer(TNOS);
return 1;
}

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
if(newkeys & KEY_LOOK_BEHIND && IsPlayerInAnyVehicle(playerid))
   {
       if(!IsNosVehicle(GetPlayerVehicleID(playerid))) return SendClientMessage(playerid,COLOR_SADDLEBROWN,".:Hata:. Bu Araca Nitro Ekleyemezsiniz !");
      PlayerPlaySound(playerid, 1133 ,0, 0, 0);
      GameTextForPlayer(playerid, "~w~10X~g~~h~~h~ Nitro~n~~b~~h~~h~FullTamir!", 500, 5);
      AddVehicleComponent(GetPlayerVehicleID(playerid),1010);
RepairVehicle(GetPlayerVehicleID(playerid));
SetVehicleHealth(GetPlayerVehicleID(playerid),1000);
nos[playerid] = 1;
TNOS = SetTimer("NosAc",4000,true);
if(!IsPlayerInAnyVehicle(playerid))
return 1;

   }

      if(newkeys == KEY_SUBMISSION)
   {
      if(IsPlayerInAnyVehicle(playerid))
      {
         if((playerid, 1153.0000, 1307.5000, -2107.5000, -2003.5000) == 1)
           {

           }
           else
           {

               PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
                GameTextForPlayer(playerid, "~w~10X~g~~h~~h~ Nitro~n~~b~~h~~h~FullTamir!", 500, 5);
                AddVehicleComponent(GetPlayerVehicleID(playerid),1010);
RepairVehicle(GetPlayerVehicleID(playerid));
SetVehicleHealth(GetPlayerVehicleID(playerid),1000);

                if(!IsPlayerInAnyVehicle(playerid))
                return 1;

               }
               }
             }
         return 1;
             }
IsNosVehicle(vehicleid)
{
    #define NO_NOS_VEHICLES 29

    new InvalidNosVehicles[NO_NOS_VEHICLES] =
    {
         581,523,462,521,463,522,461,448,468,586,
         509,481,510,472,473,493,595,484,430,453,
         452,446,454,590,569,537,538,570,449
    };

   for(new i = 0; i < NO_NOS_VEHICLES; i++)
   {
       if(GetVehicleModel(vehicleid) == InvalidNosVehicles[i])
       {
           return false;
       }
   }

	return 1;
}

public OnRconLoginAttempt(ip[], password[], success)
{
	return 1;
}

public OnPlayerUpdate(playerid)
{
    GetPlayerName(playerid, isimmm, sizeof(isimmm));
if(GetPlayerScore(playerid) >= 0 && GetPlayerScore(playerid) <= 74)
{
if(KaanRank[playerid] != 1){
KaanRank[playerid] = 1;}
TextDrawSetString(Rankim[playerid], "~w~Player");
new str2[252];
format(str2, sizeof(str2), "~b~%d~w~/75", GetPlayerScore(playerid));
TextDrawSetString(EXPiM[playerid], str2);
LevelVer(playerid,1);
}
if(GetPlayerScore(playerid) >= 75 && GetPlayerScore(playerid) <= 199)
{
if(KaanRank[playerid] != 2){
KaanRank[playerid] = 2;}
TextDrawSetString(Rankim[playerid], "~w~GM");
new str[252];
format(str, sizeof(str), "~b~%d~w~/200", GetPlayerScore(playerid));
TextDrawSetString(EXPiM[playerid],str);
LevelVer(playerid,2);
}
if(GetPlayerScore(playerid) >= 200 && GetPlayerScore(playerid) <=699)
{
if(KaanRank[playerid] != 3){
KaanRank[playerid] = 3;}
TextDrawSetString(Rankim[playerid], "~w~SGM");
new str[252];
format(str, sizeof(str), "~b~%d~w~/700", GetPlayerScore(playerid));
TextDrawSetString(EXPiM[playerid],str);
LevelVer(playerid,3);
}
if(GetPlayerScore(playerid) >= 700 && GetPlayerScore(playerid) <= 1499)
{
if(KaanRank[playerid] != 4){
KaanRank[playerid] = 3;}
TextDrawSetString(Rankim[playerid], "~w~GA");
new str[252];
format(str, sizeof(str), "~b~%d~w~/1500", GetPlayerScore(playerid));
TextDrawSetString(EXPiM[playerid],str);
LevelVer(playerid,4);
}
if(GetPlayerScore(playerid) >= 1500 && GetPlayerScore(playerid) <= 2999)
{
if(KaanRank[playerid] != 5){
KaanRank[playerid] = 3;}
TextDrawSetString(Rankim[playerid], "~w~TM");
new str[252];
format(str, sizeof(str), "~b~%d~w~/3000", GetPlayerScore(playerid));
TextDrawSetString(EXPiM[playerid],str);
LevelVer(playerid,5);
}
if(GetPlayerScore(playerid) >= 3000 && GetPlayerScore(playerid) <= 8999)
{
if(KaanRank[playerid] != 6){
KaanRank[playerid] = 3;}
TextDrawSetString(Rankim[playerid], "~w~COMA");
new str[252];
format(str, sizeof(str), "~b~%d~w~/9000", GetPlayerScore(playerid));
TextDrawSetString(EXPiM[playerid],str);
LevelVer(playerid,6);
}
if(GetPlayerScore(playerid) >= 9000 && GetPlayerScore(playerid) <= 11000)
{

}
	return 1;
}

public OnPlayerStreamIn(playerid, forplayerid)
{
	return 1;
}

public OnPlayerStreamOut(playerid, forplayerid)
{
	return 1;
}

public OnVehicleStreamIn(vehicleid, forplayerid)
{
	return 1;
}

public OnVehicleStreamOut(vehicleid, forplayerid)
{
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
//--------------------------------[Yard??m-teles-komutlar-animasyonlar-meslekler]-----------------------------------
if(dialogid == 5010)
{
if(response)
{
format(k1, sizeof(k1), "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s", k1_1, k1_2, k1_3, k1_4, k1_5, k1_6, k1_7, k1_8, k1_9, k1_10, k1_11, k1_12, k1_13);
ShowPlayerDialog(playerid,5011, DIALOG_STYLE_MSGBOX, "{7B68EE}Komutlar",k1, "Teles", "????k????");
}
}
if(dialogid == 5011)
{
if(response)
{
format(t1, sizeof(t1), "%s\n%s\n%s%s\n%s\n%s\n%s\n%s\n%s", t1_1, t1_2, t1_3, t1_4, t1_5, t1_6, t1_7, t1_8, t1_9);
    ShowPlayerDialog(playerid,5012, DIALOG_STYLE_MSGBOX, "{FF1493}Teles",t1, "Meslekler", "????k????");
}
}
if(dialogid == 5012)
{
if(response)
{
format(m1, sizeof(m1), "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s", m1_1, m1_2, m1_3, m1_4, m1_5, m1_6, m1_7, m1_8, m1_9, m1_10, m1_11, m1_12, m1_13, m1_14, m1_15, m1_16, m1_17, m1_18, m1_19);
ShowPlayerDialog(playerid,5013, DIALOG_STYLE_MSGBOX, "{ffffff}Meslekler",m1, "Animasyonlar", "????k????");
}
}
if(dialogid == 5013)
{
if(response)
{
format(a1, sizeof(a1), "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", a1_1, a1_2, a1_3, a1_4, a1_5, a1_6, a1_7, a1_8, a1_9, a1_10, a1_11);
ShowPlayerDialog(playerid,5014, DIALOG_STYLE_MSGBOX, "{ffffff}Anismanyonlar",a1, "Finish!", "????k????");
}
}
if(dialogid == (7541) && response)
{
new str[255],String[24],name[24],names[24];
GetPlayerName(playerid,name,24);
GetPlayerName(pID[playerid],names,24);
GetPVarString(playerid,"namePlayer",String,24);
format(str,255,"{FFFFFF}L??tfen {00FFFF}%s{FFFFFF} Adl?? Oyuncuya Koymak ??stedi??iniz ??d??l?? Girin.:",GetPVarString(playerid,"namePlayer",String,24));
if(!strlen(inputtext)) return ShowPlayerDialog(playerid,7541,DIALOG_STYLE_INPUT,"Kelle ??d??l??",str,"Tamam","Kapat");
SetPVarInt(pID[playerid],"kOdul",strval(inputtext));
format(str,255,"%s Adl?? Y??netici %s Adl?? Oyuncunun Kellesine $%d ??d??l Koydu..",name,names,strval(inputtext));
SendClientMessageToAll(COLOR_SPRINGGREEN,str);
SetPVarInt(pID[playerid],"Kelle",1);
SetTimerEx("Zamanb",300000,false,"i",pID[playerid]);
}
if(dialogid == DIALOGID)
	{
		if(response)
		{
			if(listitem == 0) //Paintjobs
			{
				ShowPlayerDialog(playerid, DIALOGID+1, DIALOG_STYLE_LIST, "Paintjob Se??in", "Paint Job 1\nPaint Job 2\nPaint Job 3\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 1) //Colors
			{
				ShowPlayerDialog(playerid, DIALOGID+2, DIALOG_STYLE_LIST, "Rengini Se??in", "Black\nWhite\nRed\nBlue\nGreen\nYellow\nPink\nBrown\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 2) //Exhausts
			{
				ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Egzostu Se??in", "Wheel Arch Alien Exhaust\nWheel Arch X-Flow Exhaust\nLocos Low Chromer Exhaust\nLocos Low Slamin Exhaust\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 3) //Front Bumpers
			{
				ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tamponu Se??in", "Wheel Arch Alien bumper\nWheel Arch X-Flow bumper\nLocos Low Chromer bumper\nLocos Low Slamin bumper\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 4) //Rear Bumpers
			{
				ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu se??in", "Wheel Arch Alien bumper\nWheel Arch X-Flow bumper\nLocos Low Chromer bumper\nLocos Low Slamin bumper\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 5) //Roofs
			{
				ShowPlayerDialog(playerid, DIALOGID+6, DIALOG_STYLE_LIST, "??at??y?? Se??in", "Wheel Arch Alien Roof Vent\nWheel Arch X-Flow Roof Vent\nLocos Low Hardtop Roof\nLocos Low Softtop Roof\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 6) //Spoilers
			{
				ShowPlayerDialog(playerid, DIALOGID+7, DIALOG_STYLE_LIST, "Spoiler'?? Se??in", "Alien Spoiler\nX-Flow Spoiler\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 7) //SideSkirts
			{
				ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Side Skirts\nWheel Arch X-Flow Side Skirts\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
			}
            if(listitem == 8) //Bullbars
			{
				ShowPlayerDialog(playerid, DIALOGID+9, DIALOG_STYLE_LIST, "Bullbar'?? Se??in", "Locos Low Chrome Grill\nLocos Low Chrome Bars\nLocos Low Chrome Lights\nLocos Low Chrome Bullbar\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 9) //Wheels
			{
				ShowPlayerDialog(playerid, DIALOGID+10, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Offroad\nMega\nWires\nTwist\nGrove\nImport\nAtomic\nAhab\nVirtual\nAccess\n[Di??er Sayfa]\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 10) //Car stereo
			{
				ShowPlayerDialog(playerid, DIALOGID+11, DIALOG_STYLE_LIST, "M??zik Setini Se??in.", "Bass Boost\nSuper Bass Boost\nUltra Bass Boost\nKing Bass Boost\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 11) //Tune car menu 2
			{
				ShowPlayerDialog(playerid, DIALOGID+12, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??", "Hidrolikler\nNitro x10\nAra?? Tamir\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 12) //Wheels2
			{
				ShowPlayerDialog(playerid, DIALOGID+13, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Trance\nShadow\nRimshine\nClassic\nCutter\nSwitch\nDollar\n[Geri]", "Se??", "????k????");
			}
       }
   }

   if(dialogid == DIALOGID+1) //Paintjobs
   {
		if(response)
		{
			if(listitem == 0)
			{
				if(pmodelid[playerid] == 562 ||
				pmodelid[playerid] == 565 ||
				pmodelid[playerid] == 559 ||
				pmodelid[playerid] == 561 ||
				pmodelid[playerid] == 560 ||
				pmodelid[playerid] == 575 ||
				pmodelid[playerid] == 534 ||
				pmodelid[playerid] == 567 ||
				pmodelid[playerid] == 536 ||
				pmodelid[playerid] == 535 ||
				pmodelid[playerid] == 576 ||
				pmodelid[playerid] == 558)
		        {
					new car = GetPlayerVehicleID(playerid);
					ChangeVehiclePaintjob(car,0);
					PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Paintjob 1'i ba??ar??yla arac??na ekledin.");
                    ShowPlayerDialog(playerid, DIALOGID+1, DIALOG_STYLE_LIST, "Paintjob Se??in", "Paint Job 1\nPaint Job 2\nPaint Job 3\n[Geri]", "Se??", "????k????");

				}
				else
				{
				   SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu paintjob Wheel Arch Angel ve Loco Low Co. tipi ara??lar i??indir!");
			       ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
				}
			}
			if(listitem == 1)
			{
				if(pmodelid[playerid] == 562 ||
				pmodelid[playerid] == 565 ||
				pmodelid[playerid] == 559 ||
				pmodelid[playerid] == 561 ||
				pmodelid[playerid] == 560 ||
				pmodelid[playerid] == 575 ||
				pmodelid[playerid] == 534 ||
				pmodelid[playerid] == 567 ||
				pmodelid[playerid] == 536 ||
				pmodelid[playerid] == 535 ||
				pmodelid[playerid] == 576 ||
				pmodelid[playerid] == 558)
                {
					new car = GetPlayerVehicleID(playerid);
					ChangeVehiclePaintjob(car,1);
					PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Paintjob 2'yi ba??ar??yla arac??na ekledin.");
                    ShowPlayerDialog(playerid, DIALOGID+1, DIALOG_STYLE_LIST, "Paintjob Se??in", "Paint Job 1\nPaint Job 2\nPaint Job 3\n[Geri]", "Se??", "????k????");

				}
				else
				{
				   SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu paintjob Wheel Arch Angel ve Loco Low Co. tipi ara??lar i??indir!");
			       ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
				}
			}
			if(listitem == 2)
			{
				if(pmodelid[playerid] == 562 ||
				pmodelid[playerid] == 565 ||
				pmodelid[playerid] == 559 ||
				pmodelid[playerid] == 561 ||
				pmodelid[playerid] == 560 ||
				pmodelid[playerid] == 575 ||
				pmodelid[playerid] == 534 ||
				pmodelid[playerid] == 567 ||
				pmodelid[playerid] == 536 ||
				pmodelid[playerid] == 535 ||
				pmodelid[playerid] == 576 ||
				pmodelid[playerid] == 558)
			    {
			   	   new car = GetPlayerVehicleID(playerid);
                   ChangeVehiclePaintjob(car,2);
                   PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
				   SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Paintjob 3'?? ba??ar??yla arac??na ekledin.");
                   ShowPlayerDialog(playerid, DIALOGID+1, DIALOG_STYLE_LIST, "Paintjob Se??in", "Paint Job 1\nPaint Job 2\nPaint Job 3\n[Geri]", "Se??", "????k????");
				}
				else
				{
				   SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu paintjob Wheel Arch Angel ve Loco Low Co. tipi ara??lar i??indir!");
			       ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
				}
			}
			if(listitem == 3)
			{
				ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
			}
	   }
   }

   if(dialogid == DIALOGID+2) //Colours
   {
		if(response)
		{
			if(listitem == 0)
			{
		            new car = GetPlayerVehicleID(playerid);
		            ChangeVehicleColor(car,0,0);//Black
		            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
		            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Arac??n?? Siyaha Boyad??n.");
		            ShowPlayerDialog(playerid, DIALOGID+2, DIALOG_STYLE_LIST, "Bir Renk Se??in", "Siyah\nBeyaz\nK??rm??z??\nMavi\nYe??il\nSar??\nPembe\nKahverengi\n[Geri]", "Se??", "????k????");

			}
			if(listitem == 1)
			{
			        new car = GetPlayerVehicleID(playerid);
			        ChangeVehicleColor(car,1,1);//White
			        PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			        SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Arac??n?? Beyaza Boyad??n.");
			        ShowPlayerDialog(playerid, DIALOGID+2, DIALOG_STYLE_LIST, "Bir Renk Se??in", "Siyah\nBeyaz\nK??rm??z??\nMavi\nYe??il\nSar??\nPembe\nKahverengi\n[Geri]", "Se??", "????k????");

			}
			if(listitem == 2)
			{
			        new car = GetPlayerVehicleID(playerid);
			        ChangeVehicleColor(car,3,3);//Red
			        PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			        SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Arac??n?? K??rm??z??ya Boyad??n.");
			        ShowPlayerDialog(playerid, DIALOGID+2, DIALOG_STYLE_LIST, "Bir Renk Se??in", "Siyah\nBeyaz\nK??rm??z??\nMavi\nYe??il\nSar??\nPembe\nKahverengi\n[Geri]", "Se??", "????k????");

			}
			if(listitem == 3)
			{
			        new car = GetPlayerVehicleID(playerid);
			        ChangeVehicleColor(car,79,79); //Blue
			        PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			        SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Arac??n?? Maviye Boyad??n.");
			        ShowPlayerDialog(playerid, DIALOGID+2, DIALOG_STYLE_LIST, "Bir Renk Se??in", "Siyah\nBeyaz\nK??rm??z??\nMavi\nYe??il\nSar??\nPembe\nKahverengi\n[Geri]", "Se??", "????k????");

			}
			if(listitem == 4)
			{
			        new car = GetPlayerVehicleID(playerid);
			        ChangeVehicleColor(car,86,86);//Green
			        PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			        SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Arac??n?? Ye??ile Boyad??n.");
			        ShowPlayerDialog(playerid, DIALOGID+2, DIALOG_STYLE_LIST, "Bir Renk Se??in", "Siyah\nBeyaz\nK??rm??z??\nMavi\nYe??il\nSar??\nPembe\nKahverengi\n[Geri]", "Se??", "????k????");

			}
			if(listitem == 5)
			{
			        new car = GetPlayerVehicleID(playerid);
			        ChangeVehicleColor(car,6,6);//Yellow
			        PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			        SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Arac??n?? Sar??ya Boyad??n.");
			        ShowPlayerDialog(playerid, DIALOGID+2, DIALOG_STYLE_LIST, "Bir Renk Se??in", "Siyah\nBeyaz\nK??rm??z??\nMavi\nYe??il\nSar??\nPembe\nKahverengi\n[Geri]", "Se??", "????k????");

			}
			if(listitem == 6)
           {
			        new car = GetPlayerVehicleID(playerid);
			        ChangeVehicleColor(car,126,126);//Pink
			        PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			        SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Arac??n?? Pembeye Boyad??n.");
			        ShowPlayerDialog(playerid, DIALOGID+2, DIALOG_STYLE_LIST, "Bir Renk Se??in", "Siyah\nBeyaz\nK??rm??z??\nMavi\nYe??il\nSar??\nPembe\nKahverengi\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 7)
			{
			        new car = GetPlayerVehicleID(playerid);
			        ChangeVehicleColor(car,66,66);//Brown
			        PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
	          		SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Arac??n?? Kahverengiye Boyad??n.");
			        ShowPlayerDialog(playerid, DIALOGID+2, DIALOG_STYLE_LIST, "Bir Renk Se??in", "Siyah\nBeyaz\nK??rm??z??\nMavi\nYe??il\nSar??\nPembe\nKahverengi\n[Geri]", "Se??", "????k????");
            }
            if(listitem == 8)
			{
        		    ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
            }
		}
   }

   if(dialogid == DIALOGID+3) //Exhausts
   {
		if(response)
		{
			if(listitem == 0)//Wheel Arch Cars Alien Exausts
			{
                if(pmodelid[playerid] == 562 ||
				pmodelid[playerid] == 565 ||
				pmodelid[playerid] == 559 ||
				pmodelid[playerid] == 561 ||
				pmodelid[playerid] == 560)
		        {
		            new car = GetPlayerVehicleID(playerid);
		            if(pmodelid[playerid] == 562)
		            {
		            	AddVehicleComponent(car,1034);
		            	PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
		            	SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien egzostu Elegy'ye ba??ar??yla ekledin.");
		            	ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 565)
					{
					    AddVehicleComponent(car,1046);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien egzostu Flash'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 559)
					{
					    AddVehicleComponent(car,1065);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien egzostu Jester'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 561)
					{
					    AddVehicleComponent(car,1064);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien egzostu Stratum'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 560)
					{
					    AddVehicleComponent(car,1028);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien egzostu Sultan'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 558)
					{
					    AddVehicleComponent(car,1089);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
				 	    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien egzostu Uranus'e ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
	    			}
	    			}
	  			 	else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? yanl??zca Wheel Arch Angel tipi ara??lara ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
                    }
            }
			if(listitem == 1)//Wheel Arch Cars X-Flow Exausts
            {
                if(pmodelid[playerid] == 562 ||
				pmodelid[playerid] == 565 ||
				pmodelid[playerid] == 559 ||
				pmodelid[playerid] == 561 ||
				pmodelid[playerid] == 560)
                {
			        new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 562)
			        {
			            AddVehicleComponent(car,1037);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow egzostu Elegy'ye ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 565)
					{
					    AddVehicleComponent(car,1045);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow egzostu Flash'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 559)
					{
					    AddVehicleComponent(car,1066);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow egzostu Jester'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 561)
					{
					    AddVehicleComponent(car,1059);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow egzostu Stratum'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 560)
					{
					    AddVehicleComponent(car,1029);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow egzostu Sultan'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 558)
					{
					    AddVehicleComponent(car,1092);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow egzostu Uranus'e ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? yanl??zca Wheel Arch Angel tipi ara??lara ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
            }
			if(listitem == 2)//Locos Low Co. Cars Chromer Exausts
            {
                if(pmodelid[playerid] == 575 ||
				pmodelid[playerid] == 534 ||
				pmodelid[playerid] == 567 ||
				pmodelid[playerid] == 536 ||
				pmodelid[playerid] == 576 ||
				pmodelid[playerid] == 535)

			    {
			        new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 575)
			        {
			            AddVehicleComponent(car,1044);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
		             	SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chromer egzostu Brodway'e ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 534)
					{
					    AddVehicleComponent(car,1126);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chromer egzostu Remington'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 567)
					{
					    AddVehicleComponent(car,1129);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
	                    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chromer egzostu Savanna'ya ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 536)
					{
					    AddVehicleComponent(car,1104);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chromer egzostu Blade'e ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 535)
					{
					    AddVehicleComponent(car,1113);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chromer egzostu Slamvan'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 576)
					{
					    AddVehicleComponent(car,1136);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					   	SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chromer egzostu Tornado'ya ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? yanl??zca Locos Low Car tipi ara??lara ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
            }
			if(listitem == 3)//Locos Low Co. Cars Salmin Exausts
            {
                if(pmodelid[playerid] == 575 ||
				pmodelid[playerid] == 534 ||
				pmodelid[playerid] == 567 ||
				pmodelid[playerid] == 536 ||
				pmodelid[playerid] == 576 ||
				pmodelid[playerid] == 535)
			    {
			        new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 575)
			        {
			            AddVehicleComponent(car,1043);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[INFO] Locos Low Slamin egzostu Brodway'e ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 534)
					{
					    AddVehicleComponent(car,1127);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[INFO] Locos Low Slamin egzostu Remington'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 567)
					{
					    AddVehicleComponent(car,1132);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[INFO] Locos Low Slamin egzostu Savanna'ya ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 536)
					{
					    AddVehicleComponent(car,1105);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[INFO] Locos Low Slamin egzostu Blade'e ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}

					else if(pmodelid[playerid] == 535)
					{
					    AddVehicleComponent(car,1114);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[INFO] Locos Low Slamin egzostu Slamvan'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}

					else if(pmodelid[playerid] == 576)
					{
					    AddVehicleComponent(car,1135);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[INFO] Locos Low Slamin egzostu Tornado'ya ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+3, DIALOG_STYLE_LIST, "Bir Egzost Se??in", "Wheel Arch Alien Egzost\nWheel Arch X-Flow Egzost\nLocos Low Chromer Egzost\nLocos Low Slamin Egzost\n[Geri]", "Se??", "????k????");
					}
                    }
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? yanl??zca Locos Low Car tipi ara??lara ekleyebilirssin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
            }
			if(listitem == 4)//Geri
            {
                 ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
            }
	    }
   }

   if(dialogid == DIALOGID+4)//Front Bumpers
   {
		if(response)
		{
			if(listitem == 0)//Wheel Arch Cars Alien Front Bumper
			{
                   if(pmodelid[playerid] == 562 ||
				   pmodelid[playerid] == 565 ||
				   pmodelid[playerid] == 559 ||
				   pmodelid[playerid] == 561 ||
				   pmodelid[playerid] == 560)
				   {
		            new car = GetPlayerVehicleID(playerid);
		            if(pmodelid[playerid] == 562)
		            {
		            	AddVehicleComponent(car,1171);
		            	PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
	              		SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien ??n tamponu Elegy'ye ba??ar??yla ekledin.");
		            	ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 565)
					{
					    AddVehicleComponent(car,1153);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien ??n tamponu Flash'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 559)
					{
					    AddVehicleComponent(car,1160);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien ??n tamponu Jester'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 561)
					{
					    AddVehicleComponent(car,1155);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien ??n tamponu Stratum'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 560)
					{
					    AddVehicleComponent(car,1169);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien ??n tamponu Sultan'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 558)
					{
					    AddVehicleComponent(car,1166);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
				 	    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien ??n tamponu Uranus'e ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? sadece Wheel Arch Angels tipi ara??lara ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
	                }
            }
			if(listitem == 1)//Wheel Arch Cars X-Flow Front Bumper
            {
                   if(pmodelid[playerid] == 562 ||
	               pmodelid[playerid] == 565 ||
	               pmodelid[playerid] == 559 ||
	               pmodelid[playerid] == 561 ||
                   pmodelid[playerid] == 560)
		           {

			        new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 562)
			        {
			            AddVehicleComponent(car,1172);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow ??n tamponu Elegy'ye ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 565)
					{
					    AddVehicleComponent(car,1152);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow ??n tamponu Flash'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 559)
					{
					    AddVehicleComponent(car,1173);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow ??n tamponu Jester'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 561)
					{
					    AddVehicleComponent(car,1157);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow ??n tamponu Stratum'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 560)
					{
					    AddVehicleComponent(car,1170);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow ??n tamponu Sultan'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 558)
					{
					    AddVehicleComponent(car,1165);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow ??n tamponu Uranus'e ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? sadece Wheel Arch Angels tipi ara??lara ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
		    }
			if(listitem == 2)//Locos Low Co. Car Chromer Front Bumper
            {
                if(pmodelid[playerid] == 575 ||
				pmodelid[playerid] == 534 ||
				pmodelid[playerid] == 567 ||
				pmodelid[playerid] == 536 ||
				pmodelid[playerid] == 576 ||
				pmodelid[playerid] == 535)
				{
			        new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 575)
			        {
			            AddVehicleComponent(car,1174);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chromer ??n tamponu Brodway'e ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 534)
					{
					    AddVehicleComponent(car,1179);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chromer ??n tamponu Remington'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 567)
					{
					    AddVehicleComponent(car,1189);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chromer ??n tamponu Savanna'ya ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 536)
					{
					    AddVehicleComponent(car,1182);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chromer ??n tamponu Blade'e ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 535)
					{
					    AddVehicleComponent(car,1115);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chromer ??n tamponu Slamvan'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 576)
					{
					    AddVehicleComponent(car,1191);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chromer ??n tamponu Tornado'ya ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? yanl??zca Locos Low tipi ara??lara ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
			}
			if(listitem == 3)//Locos Low Co. Salmin Front Bumper
            {
                if(pmodelid[playerid] == 575 ||
				pmodelid[playerid] == 534 ||
				pmodelid[playerid] == 567 ||
				pmodelid[playerid] == 536 ||
	            pmodelid[playerid] == 576 ||
				pmodelid[playerid] == 576)
			    {
			        new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 575)
			        {
			            AddVehicleComponent(car,1175);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Slamin ??n tamponu Brodway'e ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 534)
					{
					    AddVehicleComponent(car,1185);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Slamin ??n tamponu Remington'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 567)
					{
					    AddVehicleComponent(car,1188);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Slamin ??n tamponu Savanna'ya ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 536)
					{
					    AddVehicleComponent(car,1181);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Slamin ??n tamponu Blade'e ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
                    else if(pmodelid[playerid] == 535)
					{
					    AddVehicleComponent(car,1116);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Slamin ??n tamponu Slamvan'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 576)
					{
					    AddVehicleComponent(car,1190);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Slamin ??n tamponu Tornado'ya ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+4, DIALOG_STYLE_LIST, "??n Tampon Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? sadece Locos Low tipi ara??lara ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
                    }
            }
			if(listitem == 4)//Geri
            {
                 ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
            }
        }
   }

   if(dialogid == DIALOGID+5)//Rear Bumpers
   {
		if(response)
		{
			if(listitem == 0)//Wheel Arch Cars Alien Rear Bumper
			{
                if(pmodelid[playerid] == 562 ||
				pmodelid[playerid] == 565 ||
				pmodelid[playerid] == 559 ||
				pmodelid[playerid] == 561 ||
				pmodelid[playerid] == 560)
		        {
                    new car = GetPlayerVehicleID(playerid);
		            if(pmodelid[playerid] == 562)
		            {
		            	AddVehicleComponent(car,1149);
		            	PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
	              		SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien arka tamponu Elegy'ye ba??ar??yla ekledin.");
		            	ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 565)
					{
					    AddVehicleComponent(car,1150);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien arka tamponu Flssh'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 559)
					{
					    AddVehicleComponent(car,1159);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien arka tamponu Jester'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 561)
					{
					    AddVehicleComponent(car,1154);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien arka tamponu Stratum'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 560)
					{
					    AddVehicleComponent(car,1141);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien arka tamponu Sultan'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 558)
					{
					    AddVehicleComponent(car,1168);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
				 	    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien arka tamponu Uranus'e ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? yanl??zca Wheel Arch Angels tipi ara??lara ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
            }
			if(listitem == 1)//Wheel Arch Cars X-Flow Rear Bumper
            {
                if(pmodelid[playerid] == 562 ||
				pmodelid[playerid] == 565 ||
				pmodelid[playerid] == 559 ||
				pmodelid[playerid] == 561 ||
				pmodelid[playerid] == 560)
		        {

					new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 562)
			        {
			            AddVehicleComponent(car,1148);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch  X-Flow arka tamponu Elegy'ye ba??ar??yla ekledin.");
		                ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 565)
					{
					    AddVehicleComponent(car,1151);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch  X-Flow arka tamponu Flash'a ba??ar??yla ekledin.");
				        ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 559)
					{
					    AddVehicleComponent(car,1161);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch  X-Flow arka tamponu Jester'a ba??ar??yla ekledin.");
				        ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 561)
					{
					    AddVehicleComponent(car,1156);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch  X-Flow arka tamponu Stratum'a ba??ar??yla ekledin.");
				        ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 560)
					{
					    AddVehicleComponent(car,1140);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch  X-Flow arka tamponu Sultan'a ba??ar??yla ekledin.");
				        ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 558)
					{
					    AddVehicleComponent(car,1167);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch  X-Flow arka tamponu Uranus'e ba??ar??yla ekledin.");
				        ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? yanl??zca Wheel Arch Angels tipi ara??lara ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
            }
			if(listitem == 2)//Locos Low Co. Cars Chromer Rear Bumper
            {
                if(pmodelid[playerid] == 575 ||
				pmodelid[playerid] == 534 ||
				pmodelid[playerid] == 567 ||
				pmodelid[playerid] == 536 ||
				pmodelid[playerid] == 576 ||
				pmodelid[playerid] == 535)
			    {
			        new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 575)
			        {
			            AddVehicleComponent(car,1176);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chromer arka tamponu Brodway'e ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 534)
					{
					    AddVehicleComponent(car,1180);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chromer arka tamponu Remington'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 567)
					{
					    AddVehicleComponent(car,1187);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chromer arka tamponu Savanna'ya ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 536)
					{
					    AddVehicleComponent(car,1184);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chromer arka tamponu Blade'e ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 535)
					{
					    AddVehicleComponent(car,1109);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chromer arka tamponu Slamvan'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 576)
					{
					    AddVehicleComponent(car,1192);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chromer arka tamponu Tornado'ya ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? yanl??zca Locos Low tipi ara??lara ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
            }
			if(listitem == 3)//Locos Low Co. Cars Salmin Rear Bumper
            {
                if(pmodelid[playerid] == 575 ||
				pmodelid[playerid] == 534 ||
				pmodelid[playerid] == 567 ||
				pmodelid[playerid] == 536 ||
				pmodelid[playerid] == 576 ||
				pmodelid[playerid] == 535)
			    {
			        new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 575)
			        {
			            AddVehicleComponent(car,1177);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Slamin arka tamponu Brodway'e ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 534)
					{
					    AddVehicleComponent(car,1178);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Slamin arka tamponu Remington'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 567)
					{
					    AddVehicleComponent(car,1186);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Slamin arka tamponu Savanna'ya ba??ar??yla ekledin..");
					    ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 536)
					{
					    AddVehicleComponent(car,1183);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Slamin arka tamponu Blade'e ba??ar??yla ekledin..");
					    ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}

					else if(pmodelid[playerid] == 535)
					{
					    AddVehicleComponent(car,1110);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Slamin arka tamponu Slamvan'a ba??ar??yla ekledin..");
					    ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}

					else if(pmodelid[playerid] == 576)
					{
					    AddVehicleComponent(car,1193);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Slamin arka tamponu Tornado'ya ba??ar??yla ekledin..");
					    ShowPlayerDialog(playerid, DIALOGID+5, DIALOG_STYLE_LIST, "Arka Tamponu Se??in", "Wheel Arch Alien Tampon\nWheel Arch X-Flow Tampon\nLocos Low Chromer Tampon\nLocos Low Slamin Tampon\n[Geri]", "Se??", "????k????");
					}
                    }
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? yanl??zca Locos Low tipi ara??lara ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
            }
            if(listitem == 4)//Geri
            {
                 ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
            }
        }
   }

   if(dialogid == DIALOGID+6)//Roofs
   {
		if(response)
		{
			if(listitem == 0)//Wheel Arch Cars Alien Roof Vent
			{
                if(pmodelid[playerid] == 562 ||
				pmodelid[playerid] == 565 ||
				pmodelid[playerid] == 559 ||
				pmodelid[playerid] == 561 ||
				pmodelid[playerid] == 560)
		        {

		            new car = GetPlayerVehicleID(playerid);
		            if(pmodelid[playerid] == 562)
		            {
		            	AddVehicleComponent(car,1035);
		            	PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
	              		SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien ??at??y?? Elegy'ye ba??ar??yla ekledin.");
		            	ShowPlayerDialog(playerid, DIALOGID+6, DIALOG_STYLE_LIST, "??at??y?? Se??in", "Wheel Arch Alien ??at??\nWheel Arch X-Flow ??at??\nLocos Low Hardtop ??at??\nLocos Low Softtop ??at??\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 565)
					{
					    AddVehicleComponent(car,1054);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien ??at??y?? Flash'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+6, DIALOG_STYLE_LIST, "??at??y?? Se??in", "Wheel Arch Alien ??at??\nWheel Arch X-Flow ??at??\nLocos Low Hardtop ??at??\nLocos Low Softtop ??at??\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 559)
					{
					    AddVehicleComponent(car,1067);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien ??at??y?? Jester'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+6, DIALOG_STYLE_LIST, "??at??y?? Se??in", "Wheel Arch Alien ??at??\nWheel Arch X-Flow ??at??\nLocos Low Hardtop ??at??\nLocos Low Softtop ??at??\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 561)
					{
					    AddVehicleComponent(car,1055);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien ??at??y?? Stratum'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+6, DIALOG_STYLE_LIST, "??at??y?? Se??in", "Wheel Arch Alien ??at??\nWheel Arch X-Flow ??at??\nLocos Low Hardtop ??at??\nLocos Low Softtop ??at??\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 560)
					{
					    AddVehicleComponent(car,1032);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien ??at??y?? Sultan'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+6, DIALOG_STYLE_LIST, "??at??y?? Se??in", "Wheel Arch Alien ??at??\nWheel Arch X-Flow ??at??\nLocos Low Hardtop ??at??\nLocos Low Softtop ??at??\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 558)
					{
					    AddVehicleComponent(car,1088);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
				 	    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien ??at??y?? Uranus'e ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+6, DIALOG_STYLE_LIST, "??at??y?? Se??in", "Wheel Arch Alien ??at??\nWheel Arch X-Flow ??at??\nLocos Low Hardtop ??at??\nLocos Low Softtop ??at??\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? yanl??zca Wheel Arch Angels tipi ara??lara ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
            }
	        if(listitem == 1)//Wheel Arch Cars X-Flow Roof Vent
			{
                if(pmodelid[playerid] == 562 ||
				pmodelid[playerid] == 565 ||
				pmodelid[playerid] == 559 ||
				pmodelid[playerid] == 561 ||
				pmodelid[playerid] == 560)
		        {


			        new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 562)
			        {
			            AddVehicleComponent(car,1035);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow ??at??y?? Elegy'ye ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+6, DIALOG_STYLE_LIST, "??at??y?? Se??in", "Wheel Arch Alien ??at??\nWheel Arch X-Flow ??at??\nLocos Low Hardtop ??at??\nLocos Low Softtop ??at??\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 565)
					{
					    AddVehicleComponent(car,1053);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow ??at??y?? Flash'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+6, DIALOG_STYLE_LIST, "??at??y?? Se??in", "Wheel Arch Alien ??at??\nWheel Arch X-Flow ??at??\nLocos Low Hardtop ??at??\nLocos Low Softtop ??at??\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 559)
					{
					    AddVehicleComponent(car,1068);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow ??at??y?? Jester'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+6, DIALOG_STYLE_LIST, "??at??y?? Se??in", "Wheel Arch Alien ??at??\nWheel Arch X-Flow ??at??\nLocos Low Hardtop ??at??\nLocos Low Softtop ??at??\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 561)
					{
					    AddVehicleComponent(car,1061);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow ??at??y?? Stratum'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+6, DIALOG_STYLE_LIST, "??at??y?? Se??in", "Wheel Arch Alien ??at??\nWheel Arch X-Flow ??at??\nLocos Low Hardtop ??at??\nLocos Low Softtop ??at??\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 560)
					{
					    AddVehicleComponent(car,1033);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow ??at??y?? Sultan'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+6, DIALOG_STYLE_LIST, "??at??y?? Se??in", "Wheel Arch Alien ??at??\nWheel Arch X-Flow ??at??\nLocos Low Hardtop ??at??\nLocos Low Softtop ??at??\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 558)
					{
					    AddVehicleComponent(car,1091);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow ??at??y?? Uranus'e ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+6, DIALOG_STYLE_LIST, "??at??y?? Se??in", "Wheel Arch Alien ??at??\nWheel Arch X-Flow ??at??\nLocos Low Hardtop ??at??\nLocos Low Softtop ??at??\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? yanl??zca Wheel Arch Angels tipi ara??lara ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
			}
			if(listitem == 2)//Locos Low Co. Cars Hardtop Roof
			{
                if(pmodelid[playerid] == 567 ||
				pmodelid[playerid] == 536)
			    {
			        new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 567)
			        {
			            AddVehicleComponent(car,1130);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Hardtop ??at??y?? Brodway'e ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+6, DIALOG_STYLE_LIST, "??at??y?? Se??in", "Wheel Arch Alien ??at??\nWheel Arch X-Flow ??at??\nLocos Low Hardtop ??at??\nLocos Low Softtop ??at??\n[Geri]", "Se??", "????k????");
					}
	   				else if(pmodelid[playerid] == 536)
					{
					    AddVehicleComponent(car,1128);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Hardtop ??at??y?? Blade'e ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+6, DIALOG_STYLE_LIST, "??at??y?? Se??in", "Wheel Arch Alien ??at??\nWheel Arch X-Flow ??at??\nLocos Low Hardtop ??at??\nLocos Low Softtop ??at??\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? yanl??zca Locos Low tipi Savanna ve Blade'e ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
            }
		    if(listitem == 3)//Locos Low Co. Cars Softtop Roof
			{
                 if(pmodelid[playerid] == 567 ||
				pmodelid[playerid] == 536)
			    {
			        new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 567)
			        {
			            AddVehicleComponent(car,1131);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Softtop ??at??y?? Brodway'e ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+6, DIALOG_STYLE_LIST, "??at??y?? Se??in", "Wheel Arch Alien ??at??\nWheel Arch X-Flow ??at??\nLocos Low Hardtop ??at??\nLocos Low Softtop ??at??\n[Geri]", "Se??", "????k????");
					}
	   				else if(pmodelid[playerid] == 536)
					{
					    AddVehicleComponent(car,1103);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Softtop ??at??y?? Blade'e ba??ar??yla ekledin.");
                        ShowPlayerDialog(playerid, DIALOGID+6, DIALOG_STYLE_LIST, "??at??y?? Se??in", "Wheel Arch Alien ??at??\nWheel Arch X-Flow ??at??\nLocos Low Hardtop ??at??\nLocos Low Softtop ??at??\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? yanl??zca Locos Low tipi Savanna ve Blade'e ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
            }
            if(listitem == 4)//Geri
            {
                 ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
            }
	     }
   }

   if(dialogid == DIALOGID+7)//Spoilers
   {
		if(response)
		{
			if(listitem == 0)//Wheel Arch Cars Alien Spoilers
			{
                if(pmodelid[playerid] == 562 ||
				pmodelid[playerid] == 565 ||
				pmodelid[playerid] == 559 ||
				pmodelid[playerid] == 561 ||
				pmodelid[playerid] == 560)
		        {

		            new car = GetPlayerVehicleID(playerid);
		            if(pmodelid[playerid] == 562)
		            {
		            	AddVehicleComponent(car,1147);
		            	PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
	              		SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien Spoiler'?? Elegy'ye ba??ar??yla ekledin.");
		            	ShowPlayerDialog(playerid, DIALOGID+7, DIALOG_STYLE_LIST, "Spoiler Se??in", "Alien Spoiler\nX-Flow Spoiler\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 565)
					{
					    AddVehicleComponent(car,1049);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien Spoiler'?? Flash'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+7, DIALOG_STYLE_LIST, "Spoiler Se??in", "Alien Spoiler\nX-Flow Spoiler\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 559)
					{
					    AddVehicleComponent(car,1162);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien Spoiler'?? Jester'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+7, DIALOG_STYLE_LIST, "Spoiler Se??in", "Alien Spoiler\nX-Flow Spoiler\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 561)
					{
					    AddVehicleComponent(car,1158);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien Spoiler'?? Stratum'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+7, DIALOG_STYLE_LIST, "Spoiler Se??in", "Alien Spoiler\nX-Flow Spoiler\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 560)
					{
					    AddVehicleComponent(car,1138);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien Spoiler'?? Sultan'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+7, DIALOG_STYLE_LIST, "Spoiler Se??in", "Alien Spoiler\nX-Flow Spoiler\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 558)
					{
					    AddVehicleComponent(car,1164);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
				 	    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien Spoiler'?? Uranus'e ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+7, DIALOG_STYLE_LIST, "Spoiler Se??in", "Alien Spoiler\nX-Flow Spoiler\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? yanl??zca Wheel Arch Angels tipi ara??lara ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
    	    }
            if(listitem == 1)//Wheel Arch Cars X-Flow Spoilers
			{
                if(pmodelid[playerid] == 562 ||
				pmodelid[playerid] == 565 ||
				pmodelid[playerid] == 559 ||
				pmodelid[playerid] == 561 ||
				pmodelid[playerid] == 560)
		        {
                    new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 562)
			        {
			            AddVehicleComponent(car,1146);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow Spoiler'?? Elegy'ye ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+7, DIALOG_STYLE_LIST, "Spoiler Se??in", "Alien Spoiler\nX-Flow Spoiler\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 565)
					{
					    AddVehicleComponent(car,1150);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow Spoiler'?? Flash'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+7, DIALOG_STYLE_LIST, "Spoiler Se??in", "Alien Spoiler\nX-Flow Spoiler\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 559)
					{
					    AddVehicleComponent(car,1158);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow Spoiler'?? Jester'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+7, DIALOG_STYLE_LIST, "Spoiler Se??in", "Alien Spoiler\nX-Flow Spoiler\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 561)
					{
					    AddVehicleComponent(car,1060);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow Spoiler'?? Stratum'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+7, DIALOG_STYLE_LIST, "Spoiler Se??in", "Alien Spoiler\nX-Flow Spoiler\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 560)
					{
					    AddVehicleComponent(car,1139);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow Spoiler'?? Sultan'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+7, DIALOG_STYLE_LIST, "Spoiler Se??in", "Alien Spoiler\nX-Flow Spoiler\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 558)
					{
					    AddVehicleComponent(car,1163);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow Spoiler'?? Uranus'e ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+7, DIALOG_STYLE_LIST, "Spoiler Se??in", "Alien Spoiler\nX-Flow Spoiler\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? yanl??zca X-Flow Arch Angels tipi ara??lara ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
            }
            if(listitem == 2)//Geri
            {
                 ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
            }
	   	 }
   }

   if(dialogid == DIALOGID+8)//Sideskirts
   {
		if(response)
		{
			if(listitem == 0)//Wheel Arch Cars Alien Sideskirts
			{
                if(pmodelid[playerid] == 562 ||
				pmodelid[playerid] == 565 ||
				pmodelid[playerid] == 559 ||
				pmodelid[playerid] == 561 ||
				pmodelid[playerid] == 560)
		        {

		            new car = GetPlayerVehicleID(playerid);
		            if(pmodelid[playerid] == 562)
		            {
		            	AddVehicleComponent(car,1036);
		            	AddVehicleComponent(car,1040);
		            	PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
	              		SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien Yan Ete??i Elegy'ye ba??ar??yla ekledin.");
		            	ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Yan Etek\nWheel Arch X-Flow Yan Etek\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 565)
					{
					    AddVehicleComponent(car,1047);
					    AddVehicleComponent(car,1051);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien Yan Ete??i Flash'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Yan Etek\nWheel Arch X-Flow Yan Etek\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 559)
					{
					    AddVehicleComponent(car,1069);
					    AddVehicleComponent(car,1071);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien Yan Ete??i Jester'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Yan Etek\nWheel Arch X-Flow Yan Etek\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 561)
					{
					    AddVehicleComponent(car,1056);
					    AddVehicleComponent(car,1062);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien Yan Ete??i Stratum'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Yan Etek\nWheel Arch X-Flow Yan Etek\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 560)
					{
					    AddVehicleComponent(car,1026);
					    AddVehicleComponent(car,1027);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien Yan Ete??i Sultan'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Yan Etek\nWheel Arch X-Flow Yan Etek\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 558)
					{
					    AddVehicleComponent(car,1090);
					    AddVehicleComponent(car,1094);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
				 	    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch Alien Yan Ete??i Uranus'e ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Yan Etek\nWheel Arch X-Flow Yan Etek\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? yanl??zca Wheel Arch Angels tipi ara??lara ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
		    }
	   	    if(listitem == 1)//Wheel Arch Cars X-Flow Sideskirts
			{
                if(pmodelid[playerid] == 562 ||
				pmodelid[playerid] == 565 ||
				pmodelid[playerid] == 559 ||
				pmodelid[playerid] == 561 ||
				pmodelid[playerid] == 560)
		        {
				    new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 562)
			        {
			            AddVehicleComponent(car,1039);
			            AddVehicleComponent(car,1041);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow Yan Ete??i Elegy'ye ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Yan Etek\nWheel Arch X-Flow Yan Etek\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 565)
					{
					    AddVehicleComponent(car,1048);
					    AddVehicleComponent(car,1052);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow Yan Ete??i Flash'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Yan Etek\nWheel Arch X-Flow Yan Etek\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 559)
					{
					    AddVehicleComponent(car,1070);
					    AddVehicleComponent(car,1072);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow Yan Ete??i Jester'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Yan Etek\nWheel Arch X-Flow Yan Etek\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 561)
					{
					    AddVehicleComponent(car,1057);
					    AddVehicleComponent(car,1063);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow Yan Ete??i Stratum'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Yan Etek\nWheel Arch X-Flow Yan Etek\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 560)
					{
					    AddVehicleComponent(car,1031);
					    AddVehicleComponent(car,1030);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow Yan Ete??i Sultan'a ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Yan Etek\nWheel Arch X-Flow Yan Etek\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
					}
					else if(pmodelid[playerid] == 558)
					{
					    AddVehicleComponent(car,1093);
					    AddVehicleComponent(car,1095);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wheel Arch X-Flow Yan Ete??i Uranus'e ba??ar??yla ekledin.");
					    ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Yan Etek\nWheel Arch X-Flow Yan Etek\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? yanl??zca Wheel Arch Angels tipi ara??lara ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
		    }
		    if(listitem == 2)//Locos Low Co. Cars Chrome Strip Sideskirts
			{
                 if(pmodelid[playerid] == 575 ||
	               pmodelid[playerid] == 536 ||
	               pmodelid[playerid] == 576 ||
		 	       pmodelid[playerid] == 567)
                   {
			        new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 575)
			        {
	       		        AddVehicleComponent(car,1042);
	       		        AddVehicleComponent(car,1099);
	       		        PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chrome Strip Yan Ete??i Brodway'e ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Yan Etek\nWheel Arch X-Flow Yan Etek\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
					}
	   				else if(pmodelid[playerid] == 567)
					{
					    AddVehicleComponent(car,1102);
					    AddVehicleComponent(car,1133);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chrome Strip Yan Ete??i Savanna'ya ba??ar??yla ekledin.");
	    		        ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Yan Etek\nWheel Arch X-Flow Yan Etek\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
	                }
	                else if(pmodelid[playerid] == 576)
					{
					    AddVehicleComponent(car,1134);
					    AddVehicleComponent(car,1137);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chrome Strip Yan Ete??i Tornado'ya ba??ar??yla ekledin.");
	    		        ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Yan Etek\nWheel Arch X-Flow Yan Etek\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
	                }
	                else if(pmodelid[playerid] == 536)
					{
					    AddVehicleComponent(car,1108);
					    AddVehicleComponent(car,1107);
					    PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					    SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chrome Strip Yan Ete??i Blade'e ba??ar??yla ekledin.");
	                    ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Yan Etek\nWheel Arch X-Flow Yan Etek\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
	                }
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? yanl??zca Locos Low tipi Brodway, Savanna Tornado ve Blade'e ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
	        }
	  	    if(listitem == 3)//Locos Low Co. Cars Chrome Flames Sideskirts
			{
                if(pmodelid[playerid] == 534 ||
				pmodelid[playerid] == 534)
			    {
			        new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 534)
			        {
			            AddVehicleComponent(car,1122);
			            AddVehicleComponent(car,1101);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chrome Flames Yan ete??i Remington'a ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Yan Etek\nWheel Arch X-Flow Yan Etek\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? sadece Locos Low Car tipi Remington'a ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
			}
			if(listitem == 4)//Locos Low Co. Cars Chrome Arches Sideskirts
			{
                if(pmodelid[playerid] == 534 ||
				pmodelid[playerid] == 534)
			    {
			        new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 534)
			        {
			            AddVehicleComponent(car,1106);
			            AddVehicleComponent(car,1124);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chrome Arches Yan Ete??i Remington'a ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Yan Etek\nWheel Arch X-Flow Yan Etek\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? sadece Locos Low Car tipi Remington'a ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
			}
			if(listitem == 5)//Locos Low Co. Cars Chrome Trim Sideskirts
			{
                if(pmodelid[playerid] == 535)

			    {
			        new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 535)
			        {
			            AddVehicleComponent(car,1118);
			            AddVehicleComponent(car,1120);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chrome Trim yan ete??i Slamvan'a ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Yan Etek\nWheel Arch X-Flow Yan Etek\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? sadece Locos Low Car tipi Slamvan'a ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
			}
			if(listitem == 6)//Locos Low Co. Cars Chrome Wheelcovers Sideskirts
			{
                if(pmodelid[playerid] == 535)

			    {
			        new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 535)
			        {
			            AddVehicleComponent(car,1119);
			            AddVehicleComponent(car,1121);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chrome Wheelcover'?? Slamvan'a ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+8, DIALOG_STYLE_LIST, "Yan Ete??i Se??in", "Wheel Arch Alien Yan Etek\nWheel Arch X-Flow Yan Etek\nLocos Low Chrome Strip\nLocos Low Chrome Flames\nLocos Low Chrome Arches\nLocos Low Chrome Trim\nLocos Low Wheelcovers\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? sadece Locos Low Car tipi Slamvan'a ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
			}
			if(listitem == 7)//Geri
            {
                 ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
            }
         }
   }
   if(dialogid == DIALOGID+9)//Bullbars
   {
		if(response)
		{
			if(listitem == 0)//Locos Low Co. Cars Chrome Grill
			{
                if(pmodelid[playerid] == 534)

			    {
			        new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 534)
			        {
			            AddVehicleComponent(car,1100);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chrome Grill par??as??n?? Remington'a ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+9, DIALOG_STYLE_LIST, "Bullbar se??in", "Locos Low Chrome Grill\nLocos Low Chrome Bars\nLocos Low Chrome Lights\nLocos Low Chrome Bullbar\n[Geri]", "Se??", "????k????");
			        }
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? sadece Locos Low Car tipi Remington'a ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
			}
			if(listitem == 1)//Locos Low Co. Cars Chrome Bars
			{
                 if(pmodelid[playerid] == 534)

			    {
			        new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 534)
			        {
			            AddVehicleComponent(car,1123);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chrome Bars par??as??n?? Remington'a ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+9, DIALOG_STYLE_LIST, "Bullbar se??in", "Locos Low Chrome Grill\nLocos Low Chrome Bars\nLocos Low Chrome Lights\nLocos Low Chrome Bullbar\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? sadece Locos Low Car tipi Remington'a ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
			}
			if(listitem == 2)//Locos Low Co. Cars Chrome Lights
			{
                if(pmodelid[playerid] == 534)

			    {
			        new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 534)
			        {
			            AddVehicleComponent(car,1125);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chrome Lights par??as??n?? Remington'a ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+9, DIALOG_STYLE_LIST, "Bullbar se??in", "Locos Low Chrome Grill\nLocos Low Chrome Bars\nLocos Low Chrome Lights\nLocos Low Chrome Bullbar\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? sadece Locos Low Car tipi Remington'a ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
			}
			if(listitem == 3)//Locos Low Co. Cars Chrome Bullbar
			{
                if(pmodelid[playerid] == 535)

			    {
			        new car = GetPlayerVehicleID(playerid);
			        if(pmodelid[playerid] == 535)
			        {
			            AddVehicleComponent(car,1117);
			            PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Locos Low Chrome Lights par??as??n?? Slamvan'a ba??ar??yla ekledin.");
			            ShowPlayerDialog(playerid, DIALOGID+9, DIALOG_STYLE_LIST, "Bullbar se??in", "Locos Low Chrome Grill\nLocos Low Chrome Bars\nLocos Low Chrome Lights\nLocos Low Chrome Bullbar\n[Geri]", "Se??", "????k????");
					}
					}
					else
					{
				    SendClientMessage(playerid,COLOR_RED,"[HATA]: Bu par??ay?? sadece Locos Low Car tipi Slamvan'a ekleyebilirsin!");
					ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
					}
			}
			if(listitem == 4)//Geri
            {
                 ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
            }
       }
   }

   if(dialogid == DIALOGID+10)//Wheels
   {
		if(response)
		{
			if(listitem == 0)//Offroad
			{
                 new car = GetPlayerVehicleID(playerid);
		         AddVehicleComponent(car,1025);
		         PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
                 SendClientMessage(playerid,COLOR_YELLOW,"[INFO] Offroad tekerle??i arac??na ba??ar??yla ekledin.");
	             ShowPlayerDialog(playerid, DIALOGID+10, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Offroad\nMega\nWires\nTwist\nGrove\nImport\nAtomic\nAhab\nVirtual\nAccess\n[Di??er Sayfa]\n[Geri]", "Se??", "????k????");
	        }
            if(listitem == 1)//Mega
			{
                 new car = GetPlayerVehicleID(playerid);
			     AddVehicleComponent(car,1074);
			     PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			     SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Mega tekerle??i arac??na ba??ar??yla ekledin.");
			     ShowPlayerDialog(playerid, DIALOGID+10, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Offroad\nMega\nWires\nTwist\nGrove\nImport\nAtomic\nAhab\nVirtual\nAccess\n[Di??er Sayfa]\n[Geri]", "Se??", "????k????");
			}
            if(listitem == 2)//Wires
			{
                 new car = GetPlayerVehicleID(playerid);
	             AddVehicleComponent(car,1076);
		         SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Wires tekerle??i arac??na ba??ar??yla ekledin.");
			     ShowPlayerDialog(playerid, DIALOGID+10, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Offroad\nMega\nWires\nTwist\nGrove\nImport\nAtomic\nAhab\nVirtual\nAccess\n[Di??er Sayfa]\n[Geri]", "Se??", "????k????");
			}
	        if(listitem == 3)//Twist
			{
                 new car = GetPlayerVehicleID(playerid);
			     AddVehicleComponent(car,1078);
			     PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			     SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Twist tekerle??i arac??na ba??ar??yla ekledin.");
			     ShowPlayerDialog(playerid, DIALOGID+10, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Offroad\nMega\nWires\nTwist\nGrove\nImport\nAtomic\nAhab\nVirtual\nAccess\n[Di??er Sayfa]\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 4)//Groove
			{
                 new car = GetPlayerVehicleID(playerid);
			     AddVehicleComponent(car,1081);
			     PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			     SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Groove tekerle??i arac??na ba??ar??yla ekledin.");
		         ShowPlayerDialog(playerid, DIALOGID+10, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Offroad\nMega\nWires\nTwist\nGrove\nImport\nAtomic\nAhab\nVirtual\nAccess\n[Di??er Sayfa]\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 5)//Import
			{
                 new car = GetPlayerVehicleID(playerid);
                 AddVehicleComponent(car,1082);
                 PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
   			     SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Import tekerle??i arac??na ba??ar??yla ekledin.");
			     ShowPlayerDialog(playerid, DIALOGID+10, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Offroad\nMega\nWires\nTwist\nGrove\nImport\nAtomic\nAhab\nVirtual\nAccess\n[Di??er Sayfa]\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 6)//Atomic
			{
                 new car = GetPlayerVehicleID(playerid);
			     AddVehicleComponent(car,1085);
			     PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			     SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Atomic tekerle??i arac??na ba??ar??yla ekledin.");
                 ShowPlayerDialog(playerid, DIALOGID+10, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Offroad\nMega\nWires\nTwist\nGrove\nImport\nAtomic\nAhab\nVirtual\nAccess\n[Di??er Sayfa]\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 7)//Ahab
			{
                 new car = GetPlayerVehicleID(playerid);
			     AddVehicleComponent(car,1096);
			     PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
	          	 SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Ahab tekerle??i arac??na ba??ar??yla ekledin.");
			     ShowPlayerDialog(playerid, DIALOGID+10, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Offroad\nMega\nWires\nTwist\nGrove\nImport\nAtomic\nAhab\nVirtual\nAccess\n[Di??er Sayfa]\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 8)//Virtual
			{
                 new car = GetPlayerVehicleID(playerid);
                 AddVehicleComponent(car,1097);
                 PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
	           	 SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Virtual tekerle??i arac??na ba??ar??yla ekledin.");
                 ShowPlayerDialog(playerid, DIALOGID+10, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Offroad\nMega\nWires\nTwist\nGrove\nImport\nAtomic\nAhab\nVirtual\nAccess\n[Di??er Sayfa]\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 9)//Access
			{
                 new car = GetPlayerVehicleID(playerid);
			     AddVehicleComponent(car,1098);
			     PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
	         	 SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Access tekerle??i arac??na ba??ar??yla ekledin.");
			     ShowPlayerDialog(playerid, DIALOGID+10, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Offroad\nMega\nWires\nTwist\nGrove\nImport\nAtomic\nAhab\nVirtual\nAccess\n[Di??er Sayfa]\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 10)//Next page
			{
                 ShowPlayerDialog(playerid, DIALOGID+13, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Trance\nShadow\nRimshine\nClassic\nCutter\nSwitch\nDollar\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 11)//Geri
            {
                 ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
            }

		}
   }

   if(dialogid == DIALOGID+11)//Car Stereo
   {
		if(response)
		{
			if(listitem == 0)//Bass Boost
			{
                 new car = GetPlayerVehicleID(playerid);
		         AddVehicleComponent(car,1086);
		         PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
		         SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Stereo Bass Bost sistemini arac??na ba??ar??yla ekledin.");
		         ShowPlayerDialog(playerid, DIALOGID+11, DIALOG_STYLE_LIST, "Ses Sistemi", "Bass Boost\nSuper Bass Boost\nUltra Bass Boost\nKing Bass Boost\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 1)//Super Bass Boost
			{
		         new car = GetPlayerVehicleID(playerid);
		         AddVehicleComponent(car,1086);
		         PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
		         SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Stereo Super Bass Bost sistemini arac??na ba??ar??yla ekledin.");
		         ShowPlayerDialog(playerid, DIALOGID+11, DIALOG_STYLE_LIST, "Ses Sistemi", "Bass Boost\nSuper Bass Boost\nUltra Bass Boost\nKing Bass Boost\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 2)//Ultra Bass Boost
			{
		         new car = GetPlayerVehicleID(playerid);
		         AddVehicleComponent(car,1086);
                 PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
		         SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Ultra Bass Bost sistemini arac??na ba??ar??yla ekledin.");
		         ShowPlayerDialog(playerid, DIALOGID+11, DIALOG_STYLE_LIST, "Ses Sistemi", "Bass Boost\nSuper Bass Boost\nUltra Bass Boost\nKing Bass Boost\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 3)//King Bass Boost
			{
		         new car = GetPlayerVehicleID(playerid);
		         AddVehicleComponent(car,1086);
		         PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
		         SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: King Stereo Bass Bost sistemini arac??na ba??ar??yla ekledin.");
		         ShowPlayerDialog(playerid, DIALOGID+11, DIALOG_STYLE_LIST, "Ses Sistemi", "Bass Boost\nSuper Bass Boost\nUltra Bass Boost\nKing Bass Boost\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 4)//Geri
            {
                 ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
            }
		}
   }

   if(dialogid == DIALOGID+12)//Tune car menu 2
   {
		if(response)
		{
			if(listitem == 0)//Hydraulics
			{
		         new car = GetPlayerVehicleID(playerid);
		         AddVehicleComponent(car,1087);
		         PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
		         SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Hidrolikleri arac??na ba??ar??yla ekledin.");
		         ShowPlayerDialog(playerid, DIALOGID+12, DIALOG_STYLE_LIST, "Modifiye Men??s??", "Hidrolikler\nNitro x10\nAra?? Tamir\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 1)//Nitro x10
			{
		         new car = GetPlayerVehicleID(playerid);
		         AddVehicleComponent(car,1010);
		         PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
		         SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: 10x Nitro'yu arac??na ba??ar??yla ekledin.");
		         ShowPlayerDialog(playerid, DIALOGID+12, DIALOG_STYLE_LIST, "Modifiye Men??s??", "Hidrolikler\nNitro x10\nAra?? Tamir\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 2)//Repair Car
			{
		         new car = GetPlayerVehicleID(playerid);
		         SetVehicleHealth(car,1000);
		         PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
		         SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Arac?? Ba??ar??yla Tamir Ettin.");
		         ShowPlayerDialog(playerid, DIALOGID+12, DIALOG_STYLE_LIST, "Modifiye Men??s??", "Hidrolikler\nNitro x10\nAra?? Tamir\n[Geri]", "Se??", "????k????");
			}
			if(listitem == 3)//Geri
            {
                 ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Ara?? Modifiye Men??s??","Paint Job\nRenkler\nEgzostlar\n??n Tampon\nArka Tampon\n??at??\nSpoiler\nYan Etekler\nBullbar\nTekerlerkler\nAra?? Ses Sistemi\n[Di??er Sayfa]", "Se??", "????k????");
            }
		}
	}

   if(dialogid == DIALOGID+13)//Wheels 2
   {
		if(response)
		{
			if(listitem == 0)//Trance
            {
		         new car = GetPlayerVehicleID(playerid);
		         AddVehicleComponent(car,1084);
		         PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
		         SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Trance tekerle??i arac??na ba??ar??yla ekledin.");
		         ShowPlayerDialog(playerid, DIALOGID+13, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Trance\nShadow\nRimshine\nClassic\nCutter\nSwitch\nDollar\n[Geri]", "Se??", "????k????");
            }
            if(listitem == 1)//Shadow
            {
		         new car = GetPlayerVehicleID(playerid);
		         AddVehicleComponent(car,1073);
		         PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
		         SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Shadow tekerle??i arac??na ba??ar??yla ekledin.");
		         ShowPlayerDialog(playerid, DIALOGID+13, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Trance\nShadow\nRimshine\nClassic\nCutter\nSwitch\nDollar\n[Geri]", "Se??", "????k????");
            }
            if(listitem == 2)//Rimshine
            {
		         new car = GetPlayerVehicleID(playerid);
		         AddVehicleComponent(car,1075);
		         PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
		         SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Rimshine tekerle??i arac??na ba??ar??yla ekledin.");
		         ShowPlayerDialog(playerid, DIALOGID+13, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Trance\nShadow\nRimshine\nClassic\nCutter\nSwitch\nDollar\n[Geri]", "Se??", "????k????");
            }
            if(listitem == 3)//Classic
            {
		         new car = GetPlayerVehicleID(playerid);
		         AddVehicleComponent(car,1077);
		         PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
		         SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Classic tekerle??i arac??na ba??ar??yla ekledin.");
		         ShowPlayerDialog(playerid, DIALOGID+13, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Trance\nShadow\nRimshine\nClassic\nCutter\nSwitch\nDollar\n[Geri]", "Se??", "????k????");
            }
            if(listitem == 4)//Cutter
            {
		         new car = GetPlayerVehicleID(playerid);
		         AddVehicleComponent(car,1079);
		         PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
		         SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Cutter tekerle??i arac??na ba??ar??yla ekledin.");
		         ShowPlayerDialog(playerid, DIALOGID+13, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Trance\nShadow\nRimshine\nClassic\nCutter\nSwitch\nDollar\n[Geri]", "Se??", "????k????");
            }
            if(listitem == 5)//Switch
            {
		         new car = GetPlayerVehicleID(playerid);
		         AddVehicleComponent(car,1080);
		         PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
		         SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Switch tekerle??i arac??na ba??ar??yla ekledin.");
		         ShowPlayerDialog(playerid, DIALOGID+13, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Trance\nShadow\nRimshine\nClassic\nCutter\nSwitch\nDollar\n[Geri]", "Se??", "????k????");
            }
            if(listitem == 6)//Dollar
            {
		         new car = GetPlayerVehicleID(playerid);
		         AddVehicleComponent(car,1083);
		         PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
		         SendClientMessage(playerid,COLOR_YELLOW,"[BiLGi]: Dollar tekerle??i arac??na ba??ar??yla ekledin.");
		         ShowPlayerDialog(playerid, DIALOGID+13, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Trance\nShadow\nRimshine\nClassic\nCutter\nSwitch\nDollar\n[Geri]", "Se??", "????k????");
            }
            if(listitem == 7)//Geri
            {
		         ShowPlayerDialog(playerid, DIALOGID+10, DIALOG_STYLE_LIST, "Tekerle??i Se??in", "Offroad\nMega\nWires\nTwist\nGrove\nImport\nAtomic\nAhab\nVirtual\nAccess\n[Di??er Sayfa]\n[Geri]", "Se??", "????k????");
            }
         }
    }
	if(dialogid == 9889) // Dialog ID
	{
    if(response == 1) 	PlayerPlaySound(playerid, 1083, 0.0, 0.0, 0.0);
    else 				PlayerPlaySound(playerid, 1084, 0.0, 0.0, 0.0) 	&& TextDrawHideForPlayer(playerid, Text:Textdraw0) && TextDrawHideForPlayer(playerid, Text:Textdraw1);
		if(response)
		{

			if(listitem == 0) // Yak??n d??v???? silahlar??
			{
            ShowPlayerDialog(playerid,9779,DIALOG_STYLE_LIST,"Yak??n D??v???? Silahlar??","B????ak\nKatana\nBeyzbol Sopas??\nK??rek\nBilardo Sopas??\nJob\nGolf Sopas??\nTestere\nDildo\nBaston\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 1) // Tabancalar
	        {
	        ShowPlayerDialog(playerid,9669,DIALOG_STYLE_LIST,"Tabancalar","Colt45\nSusturuculu Colt45\nDesert Eagle\n[Geri]","Tamam","Iptal");
            }
			if(listitem == 2) // Tufekler
			{
            ShowPlayerDialog(playerid,9559,DIALOG_STYLE_LIST,"T??fekler","M4\nAK-47\nT??fek\nSniper\n[Geri]","Tamam","Iptal");
            }
			if(listitem == 3) // Pompal??lar
			{
            ShowPlayerDialog(playerid,9449,DIALOG_STYLE_LIST,"Pompal??lar","Pompal??\nCombat Shotgun\nSawn-Off Shotgun\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 4) // Yar?? makineli silahlar
			{
            ShowPlayerDialog(playerid,9339,DIALOG_STYLE_LIST,"Yar?? Makineli Silahlar","MP5\nMicro SMG\nTec9\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 5) // Bombalar
			{
            ShowPlayerDialog(playerid,9229,DIALOG_STYLE_LIST,"Bombalar","El Bombas??\nUzaktan Kumandal?? Bomba\nGaz Bombas??\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 6) // Ekipmanlar
			{
            ShowPlayerDialog(playerid,9119,DIALOG_STYLE_LIST,"Ekipmanlar","Kamera\nYang??n T??p??\nTermal G??zl??k\nGece G??r???? G??zl??????\nPara????t\nSprey\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 7) // Tan??t??m
			{
            ShowPlayerDialog(playerid,9009,DIALOG_STYLE_MSGBOX,"Tan??t??m","Bu men?? Iskender taraf??ndan haz??rlanm????t??r.\n\n--> Made By Iskender <--","Geri","Iptal");
			}
		    return 1;
	}}

        if(dialogid == 9779) // Yak??n D??v???? Silahlar??
	{
    if(response == 1) 	PlayerPlaySound(playerid, 1083, 0.0, 0.0, 0.0);
    else 				PlayerPlaySound(playerid, 1084, 0.0, 0.0, 0.0) 	&& TextDrawHideForPlayer(playerid, Text:Textdraw0) && TextDrawHideForPlayer(playerid, Text:Textdraw1);
		    if(response)
		{
			if(listitem == 0) // bicak
			{
			GivePlayerWeapon(playerid,4,1);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9779,DIALOG_STYLE_LIST,"Yak??n D??v???? Silahlar??","B????ak\nKatana\nBeyzbol Sopas??\nK??rek\nBilardo Sopas??\nJob\nGolf Sopas??\nTestere\nDildo\nBaston\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 1) // katana
			{
			GivePlayerWeapon(playerid,8,1);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9779,DIALOG_STYLE_LIST,"Yak??n D??v???? Silahlar??","B????ak\nKatana\nBeyzbol Sopas??\nK??rek\nBilardo Sopas??\nJob\nGolf Sopas??\nTestere\nDildo\nBaston\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 2) // beyzbol sopas??
			{
			GivePlayerWeapon(playerid,5,1);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9779,DIALOG_STYLE_LIST,"Yak??n D??v???? Silahlar??","B????ak\nKatana\nBeyzbol Sopas??\nK??rek\nBilardo Sopas??\nJob\nGolf Sopas??\nTestere\nDildo\nBaston\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 3) // k??rek
			{
			GivePlayerWeapon(playerid,6,1);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9779,DIALOG_STYLE_LIST,"Yak??n D??v???? Silahlar??","B????ak\nKatana\nBeyzbol Sopas??\nK??rek\nBilardo Sopas??\nJob\nGolf Sopas??\nTestere\nDildo\nBaston\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 4) // bilardo sopas??
			{
			GivePlayerWeapon(playerid,7,1);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9779,DIALOG_STYLE_LIST,"Yak??n D??v???? Silahlar??","B????ak\nKatana\nBeyzbol Sopas??\nK??rek\nBilardo Sopas??\nJob\nGolf Sopas??\nTestere\nDildo\nBaston\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 5) // job
			{
			GivePlayerWeapon(playerid,3,1);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9779,DIALOG_STYLE_LIST,"Yak??n D??v???? Silahlar??","B????ak\nKatana\nBeyzbol Sopas??\nK??rek\nBilardo Sopas??\nJob\nGolf Sopas??\nTestere\nDildo\nBaston\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 6) // golf sopas??
			{
			GivePlayerWeapon(playerid,2,1);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9779,DIALOG_STYLE_LIST,"Yak??n D??v???? Silahlar??","B????ak\nKatana\nBeyzbol Sopas??\nK??rek\nBilardo Sopas??\nJob\nGolf Sopas??\nTestere\nDildo\nBaston\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 7) // testere
			{
			GivePlayerWeapon(playerid,8,1);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9779,DIALOG_STYLE_LIST,"Yak??n D??v???? Silahlar??","B????ak\nKatana\nBeyzbol Sopas??\nK??rek\nBilardo Sopas??\nJob\nGolf Sopas??\nTestere\nDildo\nBaston\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 8) // dildo
			{
			GivePlayerWeapon(playerid,12,1);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9779,DIALOG_STYLE_LIST,"Yak??n D??v???? Silahlar??","B????ak\nKatana\nBeyzbol Sopas??\nK??rek\nBilardo Sopas??\nJob\nGolf Sopas??\nTestere\nDildo\nBaston\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 9) // baston
			{
			GivePlayerWeapon(playerid,15,1);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9779,DIALOG_STYLE_LIST,"Yak??n D??v???? Silahlar??","B????ak\nKatana\nBeyzbol Sopas??\nK??rek\nBilardo Sopas??\nJob\nGolf Sopas??\nTestere\nDildo\nBaston\n[Geri]","Tamam","Iptal");
            }
			if(listitem == 10) // geri
			{
            ShowPlayerDialog(playerid,9889,DIALOG_STYLE_LIST,"Geli??mi?? Silah Men??s?? By Iskender","Yak??n D??v???? Silahlar??\nTabancalar\nT??fekler\nPompal??lar\nYar??-Makineli Silahlar\nBombalar\nEkipmanlar\n[Tan??t??m]","Tamam","Iptal");
            }
            return 1;
}}
        if(dialogid == 9669) // tabancalar
	{
    if(response == 1) 	PlayerPlaySound(playerid, 1083, 0.0, 0.0, 0.0);
    else 				PlayerPlaySound(playerid, 1084, 0.0, 0.0, 0.0) 	&& TextDrawHideForPlayer(playerid, Text:Textdraw0) && TextDrawHideForPlayer(playerid, Text:Textdraw1);
		    if(response)
		{
			if(listitem == 0) // colt45
			{
			GivePlayerWeapon(playerid,22,500);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9669,DIALOG_STYLE_LIST,"Tabancalar","Colt45\nSusturuculu Colt45\nDesert Eagle\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 1) // susturuculu colt45
			{
			GivePlayerWeapon(playerid,23,500);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9669,DIALOG_STYLE_LIST,"Tabancalar","Colt45\nSusturuculu Colt45\nDesert Eagle\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 2) // deagle
			{
			GivePlayerWeapon(playerid,24,500);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9669,DIALOG_STYLE_LIST,"Tabancalar","Colt45\nSusturuculu Colt45\nDesert Eagle\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 3) // geri
			{
            ShowPlayerDialog(playerid,9889,DIALOG_STYLE_LIST,"Geli??mi?? Silah Men??s?? By Iskender","Yak??n D??v???? Silahlar??\nTabancalar\nT??fekler\nPompal??lar\nYar??-Makineli Silahlar\nBombalar\nEkipmanlar\n[Tan??t??m]","Tamam","Iptal");
            }
            return 1;
}}

        if(dialogid == 9559) // tufekler
	{
    if(response == 1) 	PlayerPlaySound(playerid, 1083, 0.0, 0.0, 0.0);
    else 				PlayerPlaySound(playerid, 1084, 0.0, 0.0, 0.0) 	&& TextDrawHideForPlayer(playerid, Text:Textdraw0) && TextDrawHideForPlayer(playerid, Text:Textdraw1);
		    if(response)
		{
			if(listitem == 0) // m4
			{
			GivePlayerWeapon(playerid,31,500);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9559,DIALOG_STYLE_LIST,"T??fekler","M4\nAK-47\nT??fek\nSniper\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 1) // ak47
			{
			GivePlayerWeapon(playerid,30,500);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9559,DIALOG_STYLE_LIST,"T??fekler","M4\nAK-47\nT??fek\nSniper\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 2) // tufek
			{
			GivePlayerWeapon(playerid,33,500);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9559,DIALOG_STYLE_LIST,"T??fekler","M4\nAK-47\nT??fek\nSniper\n[Geri]","Tamam","Iptal");
			}
  			if(listitem == 3) // sniper
			{
			GivePlayerWeapon(playerid,34,500);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9559,DIALOG_STYLE_LIST,"T??fekler","M4\nAK-47\nT??fek\nSniper\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 4) // geri
			{
            ShowPlayerDialog(playerid,9889,DIALOG_STYLE_LIST,"Geli??mi?? Silah Men??s?? By Iskender","Yak??n D??v???? Silahlar??\nTabancalar\nT??fekler\nPompal??lar\nYar??-Makineli Silahlar\nBombalar\nEkipmanlar\n[Tan??t??m]","Tamam","Iptal");
            }
            return 1;
}}

        if(dialogid == 9449) // pompal??lar
	{
    if(response == 1) 	PlayerPlaySound(playerid, 1083, 0.0, 0.0, 0.0);
    else 				PlayerPlaySound(playerid, 1084, 0.0, 0.0, 0.0) 	&& TextDrawHideForPlayer(playerid, Text:Textdraw0) && TextDrawHideForPlayer(playerid, Text:Textdraw1);
		    if(response)
		{
			if(listitem == 0) // pompal??
			{
			GivePlayerWeapon(playerid,25,500);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9449,DIALOG_STYLE_LIST,"Pompal??lar","Pompal??\nCombat Shotgun\nSawn-Off Shotgun\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 1) // combat
			{
			GivePlayerWeapon(playerid,27,500);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9449,DIALOG_STYLE_LIST,"Pompal??lar","Pompal??\nCombat Shotgun\nSawn-Off Shotgun\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 2) // sawn-off
			{
			GivePlayerWeapon(playerid,26,500);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9449,DIALOG_STYLE_LIST,"Pompal??lar","Pompal??\nCombat Shotgun\nSawn-Off Shotgun\n[Geri]","Tamam","Iptal");
			}
  			if(listitem == 3) // geri
			{
            ShowPlayerDialog(playerid,9889,DIALOG_STYLE_LIST,"Geli??mi?? Silah Men??s?? By Iskender","Yak??n D??v???? Silahlar??\nTabancalar\nT??fekler\nPompal??lar\nYar??-Makineli Silahlar\nBombalar\nEkipmanlar\n[Tan??t??m]","Tamam","Iptal");
            }
            return 1;
}}

        if(dialogid == 9339) // yar?? makineli silahlar
	{
    if(response == 1) 	PlayerPlaySound(playerid, 1083, 0.0, 0.0, 0.0);
    else 				PlayerPlaySound(playerid, 1084, 0.0, 0.0, 0.0) 	&& TextDrawHideForPlayer(playerid, Text:Textdraw0) && TextDrawHideForPlayer(playerid, Text:Textdraw1);
		    if(response)
		{
			if(listitem == 0) // mp5
			{
			GivePlayerWeapon(playerid,29,500);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9339,DIALOG_STYLE_LIST,"Yar?? Makineli Silahlar","MP5\nMicro SMG\nTec9\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 1) // micro smg
			{
			GivePlayerWeapon(playerid,28,500);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9339,DIALOG_STYLE_LIST,"Yar?? Makineli Silahlar","MP5\nMicro SMG\nTec9\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 2) // tec9
			{
			GivePlayerWeapon(playerid,32,500);
			SendClientMessage(playerid,YESIL,"Silah Al??nd??!");
			ShowPlayerDialog(playerid,9339,DIALOG_STYLE_LIST,"Yar?? Makineli Silahlar","MP5\nMicro SMG\nTec9\n[Geri]","Tamam","Iptal");
			}
  			if(listitem == 3) // geri
			{
            ShowPlayerDialog(playerid,9889,DIALOG_STYLE_LIST,"Geli??mi?? Silah Men??s?? By Iskender","Yak??n D??v???? Silahlar??\nTabancalar\nT??fekler\nPompal??lar\nYar??-Makineli Silahlar\nBombalar\nEkipmanlar\n[Tan??t??m]","Tamam","Iptal");
            }
            return 1;
}}

        if(dialogid == 9229) // bombalar
	{
    if(response == 1) 	PlayerPlaySound(playerid, 1083, 0.0, 0.0, 0.0);
    else 				PlayerPlaySound(playerid, 1084, 0.0, 0.0, 0.0) 	&& TextDrawHideForPlayer(playerid, Text:Textdraw0) && TextDrawHideForPlayer(playerid, Text:Textdraw1);
		    if(response)
		{
			if(listitem == 0) // el bombas??
			{
			GivePlayerWeapon(playerid,16,500);
			SendClientMessage(playerid,YESIL,"Bomba Al??nd??!");
			ShowPlayerDialog(playerid,9229,DIALOG_STYLE_LIST,"Bombalar","El Bombas??\nUzaktan Kumandal?? Bomba\nGaz Bombas??\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 1) // uzaktan kumandal?? bomba
			{
			GivePlayerWeapon(playerid,40,500);
			GivePlayerWeapon(playerid,39,500);
			SendClientMessage(playerid,YESIL,"Bomba Al??nd??!");
			ShowPlayerDialog(playerid,9229,DIALOG_STYLE_LIST,"Bombalar","El Bombas??\nUzaktan Kumandal?? Bomba\nGaz Bombas??\n[Geri]","Tamam","Iptal");
			}
            if(listitem == 2) // gaz bomba
			{
			GivePlayerWeapon(playerid,17,500);
			SendClientMessage(playerid,YESIL,"Bomba Al??nd??!");
			ShowPlayerDialog(playerid,9229,DIALOG_STYLE_LIST,"Bombalar","El Bombas??\nUzaktan Kumandal?? Bomba\nGaz Bombas??\n[Geri]","Tamam","Iptal");
			}
  			if(listitem == 3) // geri
			{
            ShowPlayerDialog(playerid,9889,DIALOG_STYLE_LIST,"Geli??mi?? Silah Men??s?? By Iskender","Yak??n D??v???? Silahlar??\nTabancalar\nT??fekler\nPompal??lar\nYar??-Makineli Silahlar\nBombalar\nEkipmanlar\n[Tan??t??m]","Tamam","Iptal");
            }
            return 1;
}}

        if(dialogid == 9119) // ekipmanlar
	{
    if(response == 1) 	PlayerPlaySound(playerid, 1083, 0.0, 0.0, 0.0);
    else 				PlayerPlaySound(playerid, 1084, 0.0, 0.0, 0.0) 	&& TextDrawHideForPlayer(playerid, Text:Textdraw0) && TextDrawHideForPlayer(playerid, Text:Textdraw1);
		    if(response)
		{
			if(listitem == 0) // kamera
			{
			GivePlayerWeapon(playerid,43,500);
			SendClientMessage(playerid,YESIL,"Ekipman Al??nd??!");
			ShowPlayerDialog(playerid,9119,DIALOG_STYLE_LIST,"Ekipmanlar","Kamera\nYang??n T??p??\nTermal G??zl??k\nGece G??r???? G??zl??????\nPara????t\nSprey\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 1) // yang??n t??p??
			{
			GivePlayerWeapon(playerid,42,500);
			SendClientMessage(playerid,YESIL,"Ekipman Al??nd??!");
			ShowPlayerDialog(playerid,9119,DIALOG_STYLE_LIST,"Ekipmanlar","Kamera\nYang??n T??p??\nTermal G??zl??k\nGece G??r???? G??zl??????\nPara????t\nSprey\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 2) // termal g??zl??k
			{
			GivePlayerWeapon(playerid,45,500);
			SendClientMessage(playerid,YESIL,"Ekipman Al??nd??!");
			ShowPlayerDialog(playerid,9119,DIALOG_STYLE_LIST,"Ekipmanlar","Kamera\nYang??n T??p??\nTermal G??zl??k\nGece G??r???? G??zl??????\nPara????t\nSprey\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 3) // gece g??r???? g??zl??????
			{
			GivePlayerWeapon(playerid,44,500);
			SendClientMessage(playerid,YESIL,"Ekipman Al??nd??!");
			ShowPlayerDialog(playerid,9119,DIALOG_STYLE_LIST,"Ekipmanlar","Kamera\nYang??n T??p??\nTermal G??zl??k\nGece G??r???? G??zl??????\nPara????t\nSprey\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 4) // para????t
			{
			GivePlayerWeapon(playerid,46,500);
			SendClientMessage(playerid,YESIL,"Ekipman Al??nd??!");
			ShowPlayerDialog(playerid,9119,DIALOG_STYLE_LIST,"Ekipmanlar","Kamera\nYang??n T??p??\nTermal G??zl??k\nGece G??r???? G??zl??????\nPara????t\nSprey\n[Geri]","Tamam","Iptal");
			}
			if(listitem == 5) // sprey
			{
			GivePlayerWeapon(playerid,41,500);
			SendClientMessage(playerid,YESIL,"Ekipman Al??nd??!");
			ShowPlayerDialog(playerid,9119,DIALOG_STYLE_LIST,"Ekipmanlar","Kamera\nYang??n T??p??\nTermal G??zl??k\nGece G??r???? G??zl??????\nPara????t\nSprey\n[Geri]","Tamam","Iptal");
			}
  			if(listitem == 6) // geri
			{
            ShowPlayerDialog(playerid,9889,DIALOG_STYLE_LIST,"Geli??mi?? Silah Men??s?? By Iskender","Yak??n D??v???? Silahlar??\nTabancalar\nT??fekler\nPompal??lar\nYar??-Makineli Silahlar\nBombalar\nEkipmanlar\n[Tan??t??m]","Tamam","Iptal");
            }
            return 1;
}}

	   if(dialogid == 9009) //tan??t??m
	   {
    if(response == 1) 	PlayerPlaySound(playerid, 1083, 0.0, 0.0, 0.0); // Secim Sesi
    else 				PlayerPlaySound(playerid, 1084, 0.0, 0.0, 0.0) 	&& TextDrawHideForPlayer(playerid, Text:Textdraw0) && TextDrawHideForPlayer(playerid, Text:Textdraw1); // Iptal Fonksiyonu
	   if(response) return ShowPlayerDialog(playerid,9889,DIALOG_STYLE_LIST,"Geli??mi?? Silah Men??s?? By Iskender","Yak??n D??v???? Silahlar??\nTabancalar\nT??fekler\nPompal??lar\nYar??-Makineli Silahlar\nBombalar\nEkipmanlar\n[Tan??t??m]","Tamam","Iptal");
	   else SendClientMessage(playerid,KIRMIZI,"Men?? Kapat??ld??");
	}
//=====================================SORUSOR S??STEM??==========================
if(dialogid == 99 && response)
	{
		format(soru,sizeof(soru),"%s",inputtext);
	    ShowPlayerDialog(playerid,100,DIALOG_STYLE_INPUT,"{FF1493}Cevap?","{F5F5F5}L??tfen cevab??n?? yaz??n??z.","Sor","Iptal");
	}

	if(dialogid == 100 && response)
	{
	    format(cevap,sizeof(cevap),"%s",inputtext);
	    new f[256];
	    format(f,sizeof(f),"{FF1493}Soru:{FFFFFF}\n%s\n\n\n{DCDCDC}L??tfen cevab?? a??a????daki kutucu??a giriniz.",soru);
	    for(new i = 0; i <= MAX_PLAYERS; i++)
	    {
	        ShowPlayerDialog(i,101,DIALOG_STYLE_INPUT,"{FF1493}Soru?",f,"Cevap","????k");
		}
	}

	if(dialogid == 101 && response)
	{
		if(!strcmp(inputtext,cevap,true))
		{

		    new f[128], n[24];
		    GetPlayerName(playerid,n,sizeof(n));
		    format(f,sizeof(f),"|> %s <|, Soruyu bildi.",n);
		    for(new i = 0; i < 500; i++)
		    {
		        if(!IsPlayerL3Admin(playerid) && GetPlayerL3AdminLevel(playerid) <= 3) continue;
		        SendClientMessage(i,COLOR_AQUA,f);
		    }

		    GivePlayerMoney(playerid,PARA);
		} else return SendClientMessage(playerid,Orange,"Yanl???? cevap.");
	}
//=========================G??YS?? S??STEM??==============================
if(dialogid == 200)
        {
            if(response)
            {
                        if(listitem ==  0)//headgear
                        {
                        new listitems[] = "{FFFFFF}1\t{55EE55}Motorsiklet Kask??\n{FFFFFF}2\t{55EE55}Motorsiklet Kask?? 2\n{FFFFFF}3\t{55EE55}Motorsiklet Kask?? 3\n{FFFFFF}4\t{55EE55}Motorsiklet Kask?? 4\n{FFFFFF}5\t{55EE55}Motorsiklet Kask?? 5\n{FFFFFF}6\t{55EE55}Sapka 1\n{FFFFFF}7\t{55EE55}Sapka 2\n{FFFFFF}8\t{55EE55}Sapka 3\n{FFFFFF}9\t{55EE55}Sapka 4\n{FFFFFF}10\t{55EE55}Sapka 6\n{FFFFFF}11\t{55EE55}Sapka 7\n{FFFFFF}12\t{55EE55}Sapka 8\n{FFFFFF}13\t{55EE55}Sapka 9\n{55EE55}>>Daha Fazla<<";
                        ShowPlayerDialog(playerid,201,DIALOG_STYLE_LIST,"{448844}Sapkalar 1/6:",listitems,"wear","back");
                        }
                        if(listitem ==  1)//glasses
                        {
                                new listitems[] = "{FFFFFF}1\t{55EE55}Gozluk 1\n{FFFFFF}2\t{55EE55}Gozluk 2\n{FFFFFF}3\t{55EE55}Gozluk 3\n{FFFFFF}4\t{55EE55}Gozluk 4\n{FFFFFF}5\t{55EE55}Gozluk 5\n{FFFFFF}6\t{55EE55}Gozluk 6\n{FFFFFF}7\t{55EE55}Gozluk 7\n{FFFFFF}8\t{55EE55}Gozluk 8\n{FFFFFF}9\t{55EE55}Gozluk 9\n{FFFFFF}10\t{55EE55}Gozluk 10";
                        ShowPlayerDialog(playerid,202,DIALOG_STYLE_LIST,"{448844}Gozlukler 1/3:",listitems,"Giy","C??k");
                        }
                        if(listitem ==  2)//Haltuch
                        {
                        new listitems[] = "{FFFFFF}1\t{55EE55}Pece 1\n{FFFFFF}2\t{55EE55}Pece  2\n{FFFFFF}3\t{55EE55}Pece  3\n{FFFFFF}4\t{55EE55}Pece  4\n{FFFFFF}5\t{55EE55}Pece  5\n{FFFFFF}6\t{55EE55}Pece 6\n{FFFFFF}7\t{55EE55}Pece  7\n{FFFFFF}8\t{55EE55}Pece  8\n{FFFFFF}9\t{55EE55}Pece  9\n{FFFFFF}10\t{55EE55}Pece  10";
                        ShowPlayerDialog(playerid,205,DIALOG_STYLE_LIST,"{448844}Peceler",listitems,"Giy","C??k");
                        }
                        if(listitem ==  3)//masks
                        {
                        new listitems[] = "{FFFFFF}1\t{55EE55}Hokey Maskesi 1\n{FFFFFF}2\t{55EE55}Hokey Maskesi 2\n{FFFFFF}3\t{55EE55}Hokey Maskesi 3\n{FFFFFF}4\t{55EE55}Zoro Maskesi\n{FFFFFF}5\t{55EE55}Kutu Maske";
                        ShowPlayerDialog(playerid,211,DIALOG_STYLE_LIST,"{448844}Maskeler",listitems,"Giy","C??k");
                        }
                        if(listitem ==  4)//remove clothes
                        {
                                new zz=0;
                                while(zz!=MAX_PLAYER_ATTACHED_OBJECTS)
                                {
                                if(IsPlayerAttachedObjectSlotUsed(playerid, zz))
                                        {
                                        RemovePlayerAttachedObject(playerid, zz);
                                        }
                                        zz++;
                                }
                        }
                }
                return 1;
        }
        if(dialogid == 201)
        {
            if(response)
            {
                        if(listitem ==  0)//MotorcrossHelmet
                        {
                SetPlayerAttachedObject(playerid, 1, 18976, 2, 0.09, 0.03, 0, 88, 75, 0);
                        }
                        if(listitem ==  1)//MotorcycleHelmet1
                        {
                            SetPlayerAttachedObject(playerid, 1, 18645, 2, 0.07, 0, 0, 88, 75, 0);
                        }
                        if(listitem ==  2)//MotorcycleHelmet2
                        {
                SetPlayerAttachedObject(playerid, 1, 18977, 2, 0.07, 0, 0, 88, 75, 0);
                        }
                        if(listitem ==  3)//MotorcycleHelmet3
                        {
                SetPlayerAttachedObject(playerid, 1, 18978, 2, 0.07, 0, 0, 88, 75, 0);
                        }
                        if(listitem ==  4)//MotorcycleHelmet4
                        {
                SetPlayerAttachedObject(playerid, 1, 18979, 2, 0.07, 0, 0, 88, 75, 0);
                        }
                        if(listitem ==  5)//HatBoater1
                        {
                SetPlayerAttachedObject(playerid, 1, 18944, 2, 0.15, 0.0, 0, 180, 0, 10);
                        }
                        if(listitem ==  6)//HatBoater2
                        {
                SetPlayerAttachedObject(playerid, 1, 18945, 2, 0.15, 0.0, 0, 180, 0, 10);
                        }
                        if(listitem ==  7)//HatBoater3
                        {
                SetPlayerAttachedObject(playerid, 1, 18946, 2, 0.15, 0.0, 0, 180, 0, 10);
                        }
                        if(listitem ==  8)//Bowler1
                        {
                SetPlayerAttachedObject(playerid, 1, 18947, 2, 0.15, 0.0, 0, 180, 0, 10);
                        }
                        if(listitem ==  9)//Bowler2
                        {
                SetPlayerAttachedObject(playerid, 1, 18948, 2, 0.15, 0.0, 0, 180, 0, 10);
                        }
                        if(listitem ==  10)//Bowler3
                        {
                SetPlayerAttachedObject(playerid, 1, 18949, 2, 0.15, 0.0, 0, 180, 0, 10);
                        }
                        if(listitem ==  11)//Bowler4
                        {
                SetPlayerAttachedObject(playerid, 1, 18950, 2, 0.15, 0.0, 0, 180, 0, 10);
                        }
                        if(listitem ==  12)//Bowler5
                        {
                SetPlayerAttachedObject(playerid, 1, 18951, 2, 0.15, 0.0, 0, 180, 0, 10);
                        }
                        if(listitem ==  13)//weiter
                        {
                        new listitems[] = "{FFFFFF}14\t{55EE55}Bere 1\n{FFFFFF}15\t{55EE55}Bere 2\n{FFFFFF}16\t{55EE55}Bere 3\n{FFFFFF}17\t{55EE55}Bere 4\n{FFFFFF}18\t{55EE55}Bere 5\n{FFFFFF}19\t{55EE55}Kep Arkadan 1\n{FFFFFF}20\t{55EE55}Kep Arkadan 2\n{FFFFFF}21\t{55EE55}Kep Arkadan 3\n{FFFFFF}22\t{55EE55}Kep Arkadan 4\n{FFFFFF}23\t{55EE55}Kep Arkadan 5\n{FFFFFF}24\t{55EE55}Kep 1\n{FFFFFF}25\t{55EE55}Kep 2\n{FFFFFF}26\t{55EE55}Sahdan Kep\n{55EE55}>>Daha Fazla<<";
                        ShowPlayerDialog(playerid,207,DIALOG_STYLE_LIST,"{FF1493}Sapkalar 2/6:",listitems,"Giy","C??k");
                        }
                }
                else
                {
                new listitems[] = "{FFFFFF}1\t{55EE55}Sapkalar\n{FFFFFF}2\t{55EE55} Gozlukler\n{FFFFFF}3\t{55EE55}Peceler\n{FFFFFF}4\t{55EE55}Maskeler\n{FFFFFF}6\t{55EE55}Giysileri Kald??r";
                ShowPlayerDialog(playerid,200,DIALOG_STYLE_LIST,"{FF1493}Giysiler Menu",listitems,"Giy","C??k");
                }
                return 1;
        }
        if(dialogid == 207)
        {
            if(response)
            {
                        if(listitem ==  0)//Beret 1
                        {
                SetPlayerAttachedObject(playerid, 1, 18921, 2, 0.15, -0.03, 0.01, 180, 0, 30);
                        }
                        if(listitem ==  1)//Beret 2
                        {
                            SetPlayerAttachedObject(playerid, 1, 18922, 2, 0.15, -0.03, 0.01, 180, 0, 30);
                        }
                        if(listitem ==  2)//Beret 3
                        {
                SetPlayerAttachedObject(playerid, 1, 18923, 2, 0.15, -0.03, 0.01, 180, 0, 30);
                        }
                        if(listitem ==  3)//Beret 4
                        {
                SetPlayerAttachedObject(playerid, 1, 18924, 2, 0.15, -0.03, 0.01, 180, 0, 30);
                        }
                        if(listitem ==  4)//Beret 5
                        {
                SetPlayerAttachedObject(playerid, 1, 18925, 2, 0.15, -0.03, 0.01, 180, 0, 30);
                        }
                        if(listitem ==  5)//CapBack1
                        {
                SetPlayerAttachedObject(playerid, 1, 18939, 2, 0.17, -0.03, 0.01, 180, 0, 30);
                        }
                        if(listitem ==  6)//CapBack2
                        {
                SetPlayerAttachedObject(playerid, 1, 18940, 2, 0.17, -0.03, 0.01, 180, 0, 30);
                        }
                        if(listitem ==  7)//CapBack3
                        {
                SetPlayerAttachedObject(playerid, 1, 18941, 2, 0.17, -0.03, 0.01, 180, 0, 30);
                        }
                        if(listitem ==  8)//CapBack4
                        {
                SetPlayerAttachedObject(playerid, 1, 18942, 2, 0.17, -0.03, 0.01, 180, 0, 30);
                        }
                        if(listitem ==  9)//CapBack5
                        {
                SetPlayerAttachedObject(playerid, 1, 18943, 2, 0.17, -0.03, 0.01, 180, 0, 30);
                        }
                        if(listitem ==  10)//CapKnit 1
                        {
                SetPlayerAttachedObject(playerid, 1, 18953, 2, 0.13, -0.03, 0.00, 180, 0, 30);
                        }
                        if(listitem ==  11)//CapKnit 2
                        {
                SetPlayerAttachedObject(playerid, 1, 18954, 2, 0.13, -0.03, 0.00, 180, 0, 30);
                        }
                        if(listitem ==  12)//CapRimUp
                        {
                SetPlayerAttachedObject(playerid, 1, 18960, 2, 0.13, 0, 0, 88, 75, 0);
                        }
                        if(listitem ==  13)//weiter
                        {
                        new listitems[] = "{FFFFFF}27\t{55EE55}T??rc?? Sapkas?? 1\n{FFFFFF}28\t{55EE55}Covboy Sapkas??1\n{FFFFFF}29\t{55EE55}Skully Sapka 1\n{FFFFFF}30\t{55EE55}Skully Sapka 2\n{FFFFFF}31\t{55EE55}Skully Sapka 3\n{FFFFFF}32\t{55EE55}Adam Sapkas?? 1\n{FFFFFF}33\t{55EE55}Adam Sapkas?? 2\n{FFFFFF}34\t{55EE55}Adam Sapkas?? 3\n{FFFFFF}35\t{55EE55}Kaplan Sapkas??\n{FFFFFF}36\t{55EE55}Cool Sapka 1\n{FFFFFF}37\t{55EE55}Cool Sapka 2\n{FFFFFF}38\t{55EE55}Cool Sapka 3\n{55EE55}\n>>Daha Fazla<<";
                        ShowPlayerDialog(playerid,208,DIALOG_STYLE_LIST,"{FF1493}Giysiler 3/6:",listitems,"Giy","C??k");
                        }
                }
                else
                {
               new listitems[] = "{FFFFFF}1\t{55EE55}Sapkalar\n{FFFFFF}2\t{55EE55} Gozlukler\n{FFFFFF}3\t{55EE55}Peceler\n{FFFFFF}4\t{55EE55}Maskeler\n{FFFFFF}6\t{55EE55}Giysileri Kald??r";
               ShowPlayerDialog(playerid,200,DIALOG_STYLE_LIST,"{FF1493}Giysiler Menu",listitems,"Giy","C??k");
                }
                return 1;
        }
        if(dialogid == 208)
        {
            if(response)
            {
                        if(listitem ==  0)//CapTrucker1
                        {
                SetPlayerAttachedObject(playerid, 1, 18961, 2, 0.14, 0, 0, 88, 75, 0);
                        }
                        if(listitem ==  1)//CowboyHat1
                        {
                SetPlayerAttachedObject(playerid, 1, 18962, 2, 0.14, 0, 0, 88, 75, 0);
                        }
                        if(listitem ==  2)//SkullyCap1
                        {
                SetPlayerAttachedObject(playerid, 1, 18964, 2, 0.125, 0.015, 0, 90, 100, 0);
                        }
                        if(listitem ==  3)//SkullyCap2
                        {
                SetPlayerAttachedObject(playerid, 1, 18965, 2, 0.125, 0.015, 0, 90, 100, 0);
                        }
                        if(listitem ==  4)//SkullyCap3
                        {
                SetPlayerAttachedObject(playerid, 1, 18966, 2, 0.125, 0.015, 0, 90, 100, 0);
                        }
                        if(listitem ==  5)//HatMan1
                        {
                SetPlayerAttachedObject(playerid, 1, 18967, 2, 0.125, 0.015, 0, 90, 80, 0);
                        }
                        if(listitem ==  6)//HatMan2
                        {
                SetPlayerAttachedObject(playerid, 1, 18968, 2, 0.125, 0.015, 0, 90, 80, 0);
                        }
                        if(listitem ==  7)//HatMan2
                        {
                SetPlayerAttachedObject(playerid, 1, 18969, 2, 0.125, 0.015, 0, 90, 80, 0);
                        }
                        if(listitem ==  8)//HatTiger
                        {
                SetPlayerAttachedObject(playerid, 1, 18970, 2, 0.125, 0.015, 0, 90, 80, 0);
                        }
                        if(listitem ==  9)//HatCool1
                        {
                SetPlayerAttachedObject(playerid, 1, 18971, 2, 0.125, 0.015, 0, 90, 80, 0);
                        }
                        if(listitem ==  10)//HatCool2
                        {
                SetPlayerAttachedObject(playerid, 1, 18972, 2, 0.125, 0.015, 0, 90, 80, 0);
                        }
                        if(listitem ==  11)//HatCool3
                        {
                SetPlayerAttachedObject(playerid, 1, 18973, 2, 0.125, 0.015, 0, 90, 80, 0);
                        }
                        if(listitem ==  12)//weiter
                        {
                        new listitems[] = "{FFFFFF}39\t{55EE55}Sapka 1\n{FFFFFF}40\t{55EE55}Sapka 2\n{FFFFFF}41\t{55EE55}Sapka 3\n{FFFFFF}42\t{55EE55}Sapka 4\n{FFFFFF}43\t{55EE55}Sapka 5\n{FFFFFF}44\t{55EE55}Kask 1\n{FFFFFF}45\t{55EE55}Kask 2\n{FFFFFF}46\t{55EE55}Kask 3\n{FFFFFF}47\t{55EE55}Kep 1\n{FFFFFF}48\t{55EE55}Kep 2\n{FFFFFF}49\t{55EE55}Kep 3\n{FFFFFF}50\t{55EE55}Kep 4\n{FFFFFF}51\t{55EE55}Kep 5\n{55EE55}>>Daha Fazla<<";
                        ShowPlayerDialog(playerid,209,DIALOG_STYLE_LIST,"{FF1493}Sapkalar 4/6:",listitems,"Giy","C??k");
                        }
                }
                else
                {
                new listitems[] = "{FFFFFF}1\t{55EE55}Sapkalar\n{FFFFFF}2\t{55EE55} Gozlukler\n{FFFFFF}3\t{55EE55}Peceler\n{FFFFFF}4\t{55EE55}Maskeler\n{FFFFFF}6\t{55EE55}Giysileri Kald??r";
                ShowPlayerDialog(playerid,200,DIALOG_STYLE_LIST,"{FF1493}Giysiler Menu",listitems,"Giy","C??k");
                }
                return 1;
        }
        if(dialogid == 209)
        {
            if(response)
            {
                        if(listitem ==  0)//CapOverEye1
                        {
                SetPlayerAttachedObject(playerid, 1, 18955, 2, 0.11, 0.02, 0, 88, 75, 0);
                        }
                        if(listitem ==  1)//CapOverEye2
                        {
                SetPlayerAttachedObject(playerid, 1, 18956, 2, 0.11, 0.02, 0, 88, 75, 0);
                        }
                        if(listitem ==  2)//CapOverEye3
                        {
                SetPlayerAttachedObject(playerid, 1, 18957, 2, 0.11, 0.02, 0, 88, 75, 0);
                        }
                        if(listitem ==  3)//CapOverEye4
                        {
                SetPlayerAttachedObject(playerid, 1, 18958, 2, 0.11, 0.02, 0, 88, 75, 0);
                        }
                        if(listitem ==  4)//CapOverEye5
                        {
                SetPlayerAttachedObject(playerid, 1, 18959, 2, 0.11, 0.02, 0, 88, 75, 0);
                        }
                        if(listitem ==  5)//Helmet1
                        {
                SetPlayerAttachedObject(playerid, 1, 18936, 2, 0.105, 0.02, 0, 0, 0, 0);
                        }
                        if(listitem ==  6)//Helmet2
                        {
                SetPlayerAttachedObject(playerid, 1, 18937, 2, 0.105, 0.02, 0, 0, 0, 0);
                        }
                        if(listitem ==  7)//Helmet3
                        {
                SetPlayerAttachedObject(playerid, 1, 18938, 2, 0.105, 0.02, 0, 0, 0, 0);
                        }
                        if(listitem ==  8)//Cap1
                        {
                SetPlayerAttachedObject(playerid, 1, 18926, 2, 0.17, 0, -0.01, 0, 0, 0);
                        }
                        if(listitem ==  9)//Cap2
                        {
                SetPlayerAttachedObject(playerid, 1, 18927, 2, 0.17, 0, -0.01, 0, 0, 0);
                        }
                        if(listitem ==  10)//Cap3
                        {
                SetPlayerAttachedObject(playerid, 1, 18928, 2, 0.17, 0, -0.01, 0, 0, 0);
                        }
                        if(listitem ==  11)//Cap4
                        {
                SetPlayerAttachedObject(playerid, 1, 18929, 2, 0.17, 0, -0.01, 0, 0, 0);
                        }
                        if(listitem ==  12)//Cap5
                        {
                SetPlayerAttachedObject(playerid, 1, 18930, 2, 0.17, 0, -0.01, 0, 0, 0);
                        }
                        if(listitem == 13)//weiter
                        {
                        new listitems[] = "{FFFFFF}52\t{55EE55}Kep 6\n{FFFFFF}53\t{55EE55}Kep 7\n{FFFFFF}54\t{55EE55}Kep 8\n{FFFFFF}55\t{55EE55}Kep 9\n{FFFFFF}56\t{55EE55}Kep 10\n{FFFFFF}57\t{55EE55}Basortusu 1\n{FFFFFF}58\t{55EE55}Basortusu 2\n{FFFFFF}59\t{55EE55}Kopftuch3\n{FFFFFF}60\t{55EE55}Basortusu 4\n{FFFFFF}61\t{55EE55}Basortusu 5\n{FFFFFF}62\t{55EE55}Basortusu 6\n{FFFFFF}63\t{55EE55}Basortusu 7\n{FFFFFF}64\t{55EE55}Basortusu 8\n{55EE55}>>Daha Fazla<<";
                        ShowPlayerDialog(playerid,210,DIALOG_STYLE_LIST,"{FF1493}Sapkalar 5/6:",listitems,"Giy","C??k");
                        }
                }
                else
                {
                new listitems[] = "{FFFFFF}1\t{55EE55}Sapkalar\n{FFFFFF}2\t{55EE55} Gozlukler\n{FFFFFF}3\t{55EE55}Peceler\n{FFFFFF}4\t{55EE55}Maskeler\n{FFFFFF}6\t{55EE55}Giysileri Kald??r";
                ShowPlayerDialog(playerid,200,DIALOG_STYLE_LIST,"{FF1493}Giysiler Menu",listitems,"Giy","C??k");
                }
                return 1;
        }
        if(dialogid == 210)
        {
            if(response)
            {
                        if(listitem ==  0)//Cap6
                        {
                SetPlayerAttachedObject(playerid, 1, 18931, 2, 0.17, 0, -0.01, 0, 0, 0);
                        }
                        if(listitem ==  1)//Cap7
                        {
                SetPlayerAttachedObject(playerid, 1, 18932, 2, 0.17, 0, -0.01, 0, 0, 0);
                        }
                        if(listitem ==  2)//Cap8
                        {
                SetPlayerAttachedObject(playerid, 1, 18933, 2, 0.17, 0, -0.01, 0, 0, 0);
                        }
                        if(listitem ==  3)//Cap9
                        {
                SetPlayerAttachedObject(playerid, 1, 18934, 2, 0.17, 0, -0.01, 0, 0, 0);
                        }
                        if(listitem ==  4)//Cap10
                        {
                SetPlayerAttachedObject(playerid, 1, 18935, 2, 0.17, 0, -0.01, 0, 0, 0);
                        }
                        if(listitem ==  5)//Kopftuch1
                        {
                SetPlayerAttachedObject(playerid, 1, 18891, 2, 0.15, -0.013, 0.001, 90, -30, -90);
                        }
                        if(listitem ==  6)//Kopftuch2
                        {
                SetPlayerAttachedObject(playerid, 1, 18892, 2, 0.15, -0.013, 0.001, 90, -30, -90);
                        }
                        if(listitem ==  7)//Kopftuch3
                        {
                SetPlayerAttachedObject(playerid, 1, 18893, 2, 0.15, -0.013, 0.001, 90, -30, -90);
                        }
                        if(listitem ==  8)//Kopftuch4
                        {
                SetPlayerAttachedObject(playerid, 1, 18894, 2, 0.15, -0.013, 0.001, 90, -30, -90);
                        }
                        if(listitem ==  9)//Kopftuch5
                        {
                SetPlayerAttachedObject(playerid, 1, 18895, 2, 0.15, -0.013, 0.001, 90, -30, -90);
                        }
                        if(listitem ==  10)//Kopftuch6
                        {
                SetPlayerAttachedObject(playerid, 1, 18896, 2, 0.15, -0.013, 0.001, 90, -30, -90);
                        }
                        if(listitem ==  11)//Kopftuch7
                        {
                SetPlayerAttachedObject(playerid, 1, 18897, 2, 0.15, -0.013, 0.001, 90, -30, -90);
                        }
                        if(listitem ==  12)//Kopftuch8
                        {
                SetPlayerAttachedObject(playerid, 1, 18898, 2, 0.15, -0.013, 0.001, 90, -30, -90);
                        }
                        if(listitem ==  13)//weiter
                        {
                        new listitems[] = "{FFFFFF}65\t{55EE55}Basortusu 9\n{FFFFFF}66\t{55EE55}Basortusu 10\n{FFFFFF}67\t{55EE55}Basortusu 11\n{FFFFFF}68\t{55EE55}Basortusu 12\n{FFFFFF}69\t{55EE55}Basortusu 13\n{FFFFFF}70\t{55EE55}Basortusu 14\n{FFFFFF}71\t{55EE55}Basortusu 15\n{FFFFFF}72\t{55EE55}Basortusu 16\n{FFFFFF}73\t{55EE55}Basortusu 17\n{FFFFFF}74\t{55EE55}Basortusu 18\n{FFFFFF}75\t{55EE55}Basortusu 19\n{FFFFFF}76\t{55EE55}Basortusu 20\n";
                        ShowPlayerDialog(playerid,212,DIALOG_STYLE_LIST,"{FF1493}Sapkalar 6/6:",listitems,"Giy","C??k");
                        }
                }
                else
                {
                new listitems[] = "{FFFFFF}1\t{55EE55}Sapkalar\n{FFFFFF}2\t{55EE55} Gozlukler\n{FFFFFF}3\t{55EE55}Peceler\n{FFFFFF}4\t{55EE55}Maskeler\n{FFFFFF}6\t{55EE55}Giysileri Kald??r";
                ShowPlayerDialog(playerid,200,DIALOG_STYLE_LIST,"{FF1493}Giysiler Menu",listitems,"Giy","C??k");
                }
                return 1;
        }
        if(dialogid == 212)
        {
            if(response)
            {
                        if(listitem ==  0)//Kopftuch9
                        {
                SetPlayerAttachedObject(playerid, 1, 18899, 2, 0.15, -0.013, 0.001, 90, -30, -90);
                        }
                        if(listitem ==  1)//Kopftuch10
                        {
                SetPlayerAttachedObject(playerid, 1, 18900, 2, 0.15, -0.013, 0.001, 90, -30, -90);
                        }
                        if(listitem ==  2)//Kopftuch11
                        {
                SetPlayerAttachedObject(playerid, 1, 18901, 2, 0.15, -0.013, 0.001, 90, -30, -90);
                        }
                        if(listitem ==  3)//Kopftuch12
                        {
                SetPlayerAttachedObject(playerid, 1, 18902, 2, 0.15, -0.013, 0.001, 90, -30, -90);
                        }
                        if(listitem ==  4)//Kopftuch13
                        {
                SetPlayerAttachedObject(playerid, 1, 18903, 2, 0.15, -0.013, 0.001, 90, -30, -90);
                        }
                        if(listitem ==  5)//Kopftuch14
                        {
                SetPlayerAttachedObject(playerid, 1, 18904, 2, 0.15, -0.013, 0.001, 90, -30, -90);
                        }
                        if(listitem ==  6)//Kopftuch15
                        {
                SetPlayerAttachedObject(playerid, 1, 18905, 2, 0.15, -0.013, 0.001, 90, -30, -90);
                        }
                        if(listitem ==  7)//Kopftuch16
                        {
                SetPlayerAttachedObject(playerid, 1, 18906, 2, 0.12, -0.02, 0.001, 90, -60, -90);
                        }
                        if(listitem ==  8)//Kopftuch17
                        {
                SetPlayerAttachedObject(playerid, 1, 18907, 2, 0.12, -0.02, 0.001, 90, -60, -90);
                        }
                        if(listitem ==  9)//Kopftuch18
                        {
                SetPlayerAttachedObject(playerid, 1, 18908, 2, 0.12, -0.02, 0.001, 90, -60, -90);
                        }
                        if(listitem ==  10)//Kopftuch19
                        {
                SetPlayerAttachedObject(playerid, 1, 18909, 2, 0.12, -0.02, 0.001, 90, -60, -90);
                        }
                        if(listitem ==  11)//Kopftuch20
                        {
                SetPlayerAttachedObject(playerid, 1, 18910, 2, 0.12, -0.02, 0.001, 90, -60, -90);
                        }
                }
                else
                {

                }
                return 1;
        }
        if(dialogid == 202)
        {
            if(response)
            {
                        if(listitem ==  0)//GlassesType1
                        {
                SetPlayerAttachedObject(playerid, 2, 19006, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  1)//GlassesType2
                        {
                SetPlayerAttachedObject(playerid, 2, 19007, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  2)//GlassesType3
                        {
                SetPlayerAttachedObject(playerid, 2, 19008, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  3)//GlassesType4
                        {
                SetPlayerAttachedObject(playerid, 2, 19009, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  4)//GlassesType5
                        {
                SetPlayerAttachedObject(playerid, 2, 19010, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  5)//GlassesType6
                        {
                SetPlayerAttachedObject(playerid, 2, 19011, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  6)//GlassesType7
                        {
                SetPlayerAttachedObject(playerid, 2, 19012, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  7)//GlassesType8
                        {
                SetPlayerAttachedObject(playerid, 2, 19013, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  8)//GlassesType9
                        {
                SetPlayerAttachedObject(playerid, 2, 19014, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  9)//GlassesType10
                        {
                SetPlayerAttachedObject(playerid, 2, 19015, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem == 10)//weiter
                        {
                                new listitems[] = "{FFFFFF}11\t{55EE55}Gozluk 11\n{FFFFFF}12\t{55EE55}Gozluk 12\n{FFFFFF}13\t{55EE55}Gozluk 13\n{FFFFFF}14\t{55EE55}Gozluk 14\n{FFFFFF}15\t{55EE55}Gozluk 15\n{FFFFFF}16\t{55EE55}Gozluk 16\n{FFFFFF}17\t{55EE55}Gozluk 17\n{FFFFFF}18\t{55EE55}Gozluk 18\n{FFFFFF}19\t{55EE55}Gozluk 19\n{FFFFFF}20\t{55EE55}Gozluk 20\n{55EE55}>>Daha Fazla<<";
                        ShowPlayerDialog(playerid,203,DIALOG_STYLE_LIST,"{FF1493}Gozlukler 2/3:",listitems,"Giy","C??k");
                        }
                }
                else
                {
                new listitems[] = "{FFFFFF}1\t{55EE55}Sapkalar\n{FFFFFF}2\t{55EE55} Gozlukler\n{FFFFFF}3\t{55EE55}Peceler\n{FFFFFF}4\t{55EE55}Maskeler\n{FFFFFF}6\t{55EE55}Giysileri Kald??r";
                ShowPlayerDialog(playerid,200,DIALOG_STYLE_LIST,"{FF1493}Giysiler Menu",listitems,"Giy","C??k");
                }
                return 1;
        }
        if(dialogid == 203)
        {
            if(response)
            {
                        if(listitem ==  0)//GlassesType11
                        {
                SetPlayerAttachedObject(playerid, 2, 19016, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  1)//GlassesType12
                        {
                SetPlayerAttachedObject(playerid, 2, 19017, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  2)//GlassesType13
                        {
                SetPlayerAttachedObject(playerid, 2, 19018, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  3)//GlassesType14
                        {
                SetPlayerAttachedObject(playerid, 2, 19019, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  4)//GlassesType15
                        {
                SetPlayerAttachedObject(playerid, 2, 19020, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  5)//GlassesType16
                        {
                SetPlayerAttachedObject(playerid, 2, 19021, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  6)//GlassesType17
                        {
                SetPlayerAttachedObject(playerid, 2, 19022, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  7)//GlassesType18
                        {
                SetPlayerAttachedObject(playerid, 2, 19023, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  8)//GlassesType19
                        {
                SetPlayerAttachedObject(playerid, 2, 19024, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  9)//GlassesType20
                        {
                SetPlayerAttachedObject(playerid, 2, 19025, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem == 10)//weiter
                        {
                                new listitems[] = "{FFFFFF}21\t{55EE55}Gozluk 21\n{FFFFFF}22\t{55EE55}Gozluk 22\n{FFFFFF}23\t{55EE55}Gozluk 23\n{FFFFFF}24\t{55EE55}Gozluk 24\n{FFFFFF}25\t{55EE55}Gozluk 25\n{FFFFFF}26\t{55EE55}Gozluk 26\n{FFFFFF}27\t{55EE55}Gozluk 27\n{FFFFFF}28\t{55EE55}Gozluk 28\n{FFFFFF}29\t{55EE55}Gozluk 29\n{FFFFFF}30\t{55EE55}Gozluk 30";
                        ShowPlayerDialog(playerid,204,DIALOG_STYLE_LIST,"{FF1493}Gozlukler 3/3:",listitems,"Giy","C??k");
                        }
                }
                else
                {
                new listitems[] = "{FFFFFF}1\t{55EE55}Sapkalar\n{FFFFFF}2\t{55EE55} Gozlukler\n{FFFFFF}3\t{55EE55}Peceler\n{FFFFFF}4\t{55EE55}Maskeler\n{FFFFFF}6\t{55EE55}Giysileri Kald??r";
                ShowPlayerDialog(playerid,200,DIALOG_STYLE_LIST,"{FF1493}Giysiler Menu",listitems,"Giy","C??k");
                }
                return 1;
        }
        if(dialogid == 204)
        {
            if(response)
            {
                        if(listitem ==  0)//GlassesType21
                        {
                SetPlayerAttachedObject(playerid, 2, 19026, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  1)//GlassesType22
                        {
                SetPlayerAttachedObject(playerid, 2, 19027, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  2)//GlassesType23
                        {
                SetPlayerAttachedObject(playerid, 2, 19028, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  3)//GlassesType24
                        {
                SetPlayerAttachedObject(playerid, 2, 19029, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  4)//GlassesType25
                        {
                SetPlayerAttachedObject(playerid, 2, 19030, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  5)//GlassesType26
                        {
                SetPlayerAttachedObject(playerid, 2, 19031, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  6)//GlassesType27
                        {
                SetPlayerAttachedObject(playerid, 2, 19032, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  7)//GlassesType28
                        {
                SetPlayerAttachedObject(playerid, 2, 19033, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  8)//GlassesType29
                        {
                SetPlayerAttachedObject(playerid, 2, 19034, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                        if(listitem ==  9)//GlassesType30
                        {
                SetPlayerAttachedObject(playerid, 2, 19035, 2, 0.09, 0.04, 0, 88, 75, 0);
                        }
                }
                else
                {
                new listitems[] = "{FFFFFF}1\t{55EE55}Sapkalar\n{FFFFFF}2\t{55EE55} Gozlukler\n{FFFFFF}3\t{55EE55}Peceler\n{FFFFFF}4\t{55EE55}Maskeler\n{FFFFFF}6\t{55EE55}Giysileri Kald??r";
                ShowPlayerDialog(playerid,200,DIALOG_STYLE_LIST,"{FF1493}Giysiler Menu",listitems,"Giy","C??k");
                }
                return 1;
        }
        if(dialogid == 205)
        {
            if(response)
            {
                        if(listitem ==  0)//bandanna1
                        {
                SetPlayerAttachedObject(playerid, 3, 18911, 2, -0.08, 0.03, 0.0, 90, -180, -90);
                        }
                        if(listitem ==  1)//bandanna2
                        {
                SetPlayerAttachedObject(playerid, 3, 18912, 2, -0.08, 0.03, 0.0, 90, -180, -90);
                        }
                        if(listitem ==  2)//bandanna3
                        {
                SetPlayerAttachedObject(playerid, 3, 18913, 2, -0.08, 0.03, 0.0, 90, -180, -90);
                        }
                        if(listitem ==  3)//bandanna4
                        {
                SetPlayerAttachedObject(playerid, 3, 18914, 2, -0.08, 0.03, 0.0, 90, -180, -90);
                        }
                        if(listitem ==  4)//bandanna5
                        {
                SetPlayerAttachedObject(playerid, 3, 18915, 2, -0.08, 0.03, 0.0, 90, -180, -90);
                        }
                        if(listitem ==  5)//bandanna6
                        {
                SetPlayerAttachedObject(playerid, 3, 18916, 2, -0.08, 0.03, 0.0, 90, -180, -90);
                        }
                        if(listitem ==  6)//bandanna7
                        {
                SetPlayerAttachedObject(playerid, 3, 18917, 2, -0.08, 0.03, 0.0, 90, -180, -90);
                        }
                        if(listitem ==  7)//bandanna8
                        {
                SetPlayerAttachedObject(playerid, 3, 18918, 2, -0.08, 0.03, 0.0, 90, -180, -90);
                        }
                        if(listitem ==  8)//bandanna9
                        {
                SetPlayerAttachedObject(playerid, 3, 18919, 2, -0.08, 0.03, 0.0, 90, -180, -90);
                        }
                        if(listitem ==  9)//bandanna10
                        {
                SetPlayerAttachedObject(playerid, 3, 18920, 2, -0.08, 0.03, 0.0, 90, -180, -90);
                        }
                }
                else
                {
                new listitems[] = "{FFFFFF}1\t{55EE55}Sapkalar\n{FFFFFF}2\t{55EE55} Gozlukler\n{FFFFFF}3\t{55EE55}Peceler\n{FFFFFF}4\t{55EE55}Maskeler\n{FFFFFF}6\t{55EE55}Giysileri Kald??r";
                ShowPlayerDialog(playerid,200,DIALOG_STYLE_LIST,"{FF1493}Giysiler Menu",listitems,"Giy","C??k");
                }
                return 1;
        }
        if(dialogid == 211)
        {
            if(response)
            {
                        if(listitem ==  0)//Hockeymask1
                        {
                SetPlayerAttachedObject(playerid, 1, 19036, 2, 0.107, 0.020, 0.0, 90, 90, 0);
                        }
                        if(listitem ==  1)//Hockeymask2
                        {
                SetPlayerAttachedObject(playerid, 1, 19037, 2, 0.107, 0.020, 0.0, 90, 90, 0);
                        }
                        if(listitem ==  2)//Hockeymask3
                        {
                SetPlayerAttachedObject(playerid, 1, 19038, 2, 0.107, 0.020, 0.0, 90, 90, 0);
                        }
                        if(listitem ==  3)//Zorromask
                        {
                SetPlayerAttachedObject(playerid, 1, 18974, 2, 0.098, 0.0258, 0.0, 90, 90, 0);
                        }
                        if(listitem ==  4)//Boxing
                        {
                SetPlayerAttachedObject(playerid, 1, 18952, 2, 0.105, 0.01, 0.0, 0, 0, 0);
                        }
                }
                else
                {
                new listitems[] = "{FFFFFF}1\t{55EE55}Sapkalar\n{FFFFFF}2\t{55EE55} Gozlukler\n{FFFFFF}3\t{55EE55}Peceler\n{FFFFFF}4\t{55EE55}Maskeler\n{FFFFFF}6\t{55EE55}Giysileri Kald??r";
                ShowPlayerDialog(playerid,200,DIALOG_STYLE_LIST,"{FF1493}Giysiler Menu",listitems,"Giy","C??k");
                }
return 1;
}

//==============================KAY??T==========
if(dialogid == Kayit)
{

  if(response)
  {
  new dosya[128];
  new string[128];
  new isimm[MAX_PLAYER_NAME];
  GetPlayerName(playerid, isimm, sizeof(isimm));
  format(dosya,sizeof(dosya),"KeYF-i/%s.ini",isimm);

  if(strlen(inputtext) == 0)
  {
   format(string, sizeof string, "{D3D3D3}Kay??t\n\nHo??geldin {00FFFF}%s! \n{D3D3D3}Sunucumuzda Bu ??sim Kayitl?? De??il!\nL??tfen Bir ??ifre Yazarak Kay??t Olunuz!", isimm);
   ShowPlayerDialog(playerid, Kayit, DIALOG_STYLE_INPUT, "{FF1493}[Yaramaz] Clan Server", string, "[Yaramaz]!", "??ptal");

   return 0;
}
   if(!fexist(dosya))
   {
			p[playerid][Log] = 1;
			dini_Create(L3);
			dini_IntSet(L3,"Level",0);

       dini_Create(dosya);
       dini_IntSet(dosya,"Sifre", udb_hash(inputtext));
       dini_IntSet(dosya,"Skor", GetPlayerScore(playerid));
       dini_IntSet(dosya,"Para", GetPlayerMoney(playerid));
       dini_IntSet(dosya,"Olme", PlayerInfo[playerid][Olme]);
       dini_IntSet(dosya,"Oldurme",PlayerInfo[playerid][Oldurme]);
       dini_IntSet(dosya,"WantedLevel",GetPlayerWantedLevel(playerid));
       dini_IntSet(dosya,"Skinid",GetPlayerSkin(playerid));
       format(string, sizeof string, "{D3D3D3}Giri??\n\nHo??geldin {00FFFF}%s! \n{D3D3D3}Sunucumuzda Kay??tl?? Bir Hesab??n??z Var\nL??tfen ??ifrenizi Giriniz", isim);
       ShowPlayerDialog(playerid, Giris, DIALOG_STYLE_INPUT, "{FF1493}[Yaramaz] Clan Server", string, "Giri??!", "??ptal");
       GetPlayerName(playerid, isim, sizeof(isim));

     }

  }

}
if(dialogid == Giris)
{
   if(response)
{


   new dosya[128];
   new string[128];
   new isimm[124];
   if(strlen(inputtext) == 0)
{

  GetPlayerName(playerid,isim, sizeof isimm);
  format(string, sizeof string, "{D3D3D3}Giri??\n\nHo??geldin {00FFFF}%s! \n{D3D3D3}Sunucumuzda Kay??tl?? Bir Hesab??n??z Var\nL??tfen ??ifrenizi Giriniz", isimm);
  ShowPlayerDialog(playerid, Giris, DIALOG_STYLE_INPUT, "{FF1493}[Yaramaz] Clan Server", string, "Giri??!", "??ptal");
  return 0;
}
new name[MAX_PLAYER_NAME];
GetPlayerName(playerid ,name ,sizeof(name));
format(dosya,sizeof(dosya),"KeYF-i/%s.ini",name);
if(fexist(dosya))
{


  new sifre = dini_Int(dosya, "Sifre");
  if(udb_hash(inputtext) != sifre)
{



 SendClientMessage(playerid,COLOR_GOLD,"'Yanl???? ??ifre!!!'Tekrar deneyin!");
 GetPlayerName(playerid, isim, sizeof(isim));
  TogglePlayerSpectating(playerid, 1);
	    GirisYapti[playerid] = 0;
        GetPlayerName(playerid, isimm, sizeof(isimm));
        format(dosya,sizeof(dosya),"KeYF-i/%s.ini",isimm);
        if(!fexist(dosya))
        {

            format(string, sizeof string, "{D3D3D3}Ho??geldin {00FFFF}%s\n{D3D3D3}Sunucumuzda Sizin Ad??n??za Kay??tl?? Bir Hesap Bulunamad??\nL??tfen ??ifre Girin Ve Kay??t Olun.!", isimm);
            ShowPlayerDialog(playerid,Kayit,DIALOG_STYLE_INPUT, "{FF1493}[Yaramaz] Clan Server", string,"Kayit", "??ptal");
        }
if(fexist(dosya))
{
   format(string, sizeof string, "{FFD700}Yanl???? ??ifre Girdiniz!!!\n{D3D3D3}L??tfen ??ifreyi Do??ru Yaz??p Tekrar Giri?? Yap??n??z.",isimm);
   ShowPlayerDialog(playerid,Giris,DIALOG_STYLE_INPUT, "{FF1493}[Yaramaz] Clan Server", string, "Giri??","??ptal");
}

 }
else
{


        GirisYapti[playerid] = 1;
        ResetPlayerMoney(playerid);
        SetPlayerScore(playerid, dini_Int(dosya,"Skor"));
        GivePlayerMoney(playerid, dini_Int(dosya,"Para"));
        PlayerInfo[playerid][Olme] = dini_Int(dosya,"Olme");
        PlayerInfo[playerid][Oldurme] = dini_Int(dosya,"Oldurme");
        SetPlayerWantedLevel(playerid, dini_Int(dosya,"WantedLevel"));
        SetPlayerSkin(playerid, dini_Int(dosya,"Skinid"));
        SendClientMessage(playerid,COLOR_AQUA, "??ifre Onayland?? | ??yi Oyunlar...");
        TogglePlayerSpectating(playerid, 0);
	        	p[playerid][Log] = 2;
				p[playerid][Level] = dini_Int(L3,"Level");
				new f[128];
				format(f,sizeof(f),"%s, Giri?? yapt??n??z, Level: %d",isim,p[playerid][Level]);
				SendClientMessage(playerid,RENK_FISTIK,f);


}
    }

     }

  }

return 0;
}


public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	return 1;
}

stock LevelVer(playerid, lv)
{
	p[playerid][Level] = lv;
}
