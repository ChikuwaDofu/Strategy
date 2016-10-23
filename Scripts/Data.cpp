#include"DxLib.h"
#include"Suken.h"
#include"Data.h"
#include"General.h"

const std::string turn="turnnow";
const std::string turncountry="countrynow";
const std::string unitH[5][20]={"H11","H12","H13","H14","H15","H16","H17","H18","H19","H110","H111","H112","H113","H114","H115","H116","H117","H118","H119","H120","H21","H22","H23","H24","H25","H26","H27","H28","H29","H210","H211","H212","H213","H214","H215","H216","H217","H218","H219","H220","H31","H32","H33","H34","H35","H36","H37","H38","H39","H310","H311","H312","H313","H314","H315","H316","H317","H318","H319","H320","H41","H42","H43","H44","H45","H46","H47","H48","H49","H410","H411","H412","H413","H414","H415","H416","H417","H418","H419","H420"};
const std::string unitT[5][20]={"T11","T12","T13","T14","T15","T16","T17","T18","T19","T110","T111","T112","T113","T114","T115","T116","T117","T118","T119","T120","T21","T22","T23","T24","T25","T26","T27","T28","T29","T210","T211","T212","T213","T214","T215","T216","T217","T218","T219","T220","T31","T32","T33","T34","T35","T36","T37","T38","T39","T310","T311","T312","T313","T314","T315","T316","T317","T318","T319","T320","T41","T42","T43","T44","T45","T46","T47","T48","T49","T410","T411","T412","T413","T414","T415","T416","T417","T418","T419","T420"};
const std::string unitX[5][20]={"X11","X12","X13","X14","X15","X16","X17","X18","X19","X110","X111","X112","X113","X114","X115","X116","X117","X118","X119","X120","X21","X22","X23","X24","X25","X26","X27","X28","X29","X210","X211","X212","X213","X214","X215","X216","X217","X218","X219","X220","X31","X32","X33","X34","X35","X36","X37","X38","X39","X310","X311","X312","X313","X314","X315","X316","X317","X318","X319","X320","X41","X42","X43","X44","X45","X46","X47","X48","X49","X410","X411","X412","X413","X414","X415","X416","X417","X418","X419","X420"};
const std::string unitY[5][20]={"Y11","Y12","Y13","Y14","Y15","Y16","Y17","Y18","Y19","Y110","Y111","Y112","Y113","Y114","Y115","Y116","Y117","Y118","Y119","Y120","Y21","Y22","Y23","Y24","Y25","Y26","Y27","Y28","Y29","Y210","Y211","Y212","Y213","Y214","Y215","Y216","Y217","Y218","Y219","Y220","Y31","Y32","Y33","Y34","Y35","Y36","Y37","Y38","Y39","Y310","Y311","Y312","Y313","Y314","Y315","Y316","Y317","Y318","Y319","Y320","Y41","Y42","Y43","Y44","Y45","Y46","Y47","Y48","Y49","Y410","Y411","Y412","Y413","Y414","Y415","Y416","Y417","Y418","Y419","Y420"};
const std::string unitM[5][20]={"M11","M12","M13","M14","M15","M16","M17","M18","M19","M110","M111","M112","M113","M114","M115","M116","M117","M118","M119","M120","M21","M22","M23","M24","M25","M26","M27","M28","M29","M210","M211","M212","M213","M214","M215","M216","M217","M218","M219","M220","M31","M32","M33","M34","M35","M36","M37","M38","M39","M310","M311","M312","M313","M314","M315","M316","M317","M318","M319","M320","M41","M42","M43","M44","M45","M46","M47","M48","M49","M410","M411","M412","M413","M414","M415","M416","M417","M418","M419","M420"};
const std::string unitP[5][20]={"P11","P12","P13","P14","P15","P16","P17","P18","P19","P110","P111","P112","P113","P114","P115","P116","P117","P118","P119","P120","P21","P22","P23","P24","P25","P26","P27","P28","P29","P210","P211","P212","P213","P214","P215","P216","P217","P218","P219","P220","P31","P32","P33","P34","P35","P36","P37","P38","P39","P310","P311","P312","P313","P314","P315","P316","P317","P318","P319","P320","P41","P42","P43","P44","P45","P46","P47","P48","P49","P410","P411","P412","P413","P414","P415","P416","P417","P418","P419","P420"};
const std::string unitA[5][20]={"A11","A12","A13","A14","A15","A16","A17","A18","A19","A110","A111","A112","A113","A114","A115","A116","A117","A118","A119","A120","A21","A22","A23","A24","A25","A26","A27","A28","A29","A210","A211","A212","A213","A214","A215","A216","A217","A218","A219","A220","A31","A32","A33","A34","A35","A36","A37","A38","A39","A310","A311","A312","A313","A314","A315","A316","A317","A318","A319","A320","A41","A42","A43","A44","A45","A46","A47","A48","A49","A410","A411","A412","A413","A414","A415","A416","A417","A418","A419","A420"};
const std::string money[5]={"Money1","Money2","Money3","Money4","Money5"};
const std::string owner[20][20]={"Owner 1","Owner 2","Owner 3","Owner 4","Owner 5","Owner 6","Owner 7","Owner 8","Owner 9","Owner 10","Owner 11","Owner 12","Owner 13","Owner 14","Owner 15","Owner 16","Owner 17","Owner 18","Owner 19","Owner 20","Owner 21","Owner 22","Owner 23","Owner 24","Owner 25","Owner 26","Owner 27","Owner 28","Owner 29","Owner 30","Owner 31","Owner 32","Owner 33","Owner 34","Owner 35","Owner 36","Owner 37","Owner 38","Owner 39","Owner 40","Owner 41","Owner 42","Owner 43","Owner 44","Owner 45","Owner 46","Owner 47","Owner 48","Owner 49","Owner 50","Owner 51","Owner 52","Owner 53","Owner 54","Owner 55","Owner 56","Owner 57","Owner 58","Owner 59","Owner 60","Owner 61","Owner 62","Owner 63","Owner 64","Owner 65","Owner 66","Owner 67","Owner 68","Owner 69","Owner 70","Owner 71","Owner 72","Owner 73","Owner 74","Owner 75","Owner 76","Owner 77","Owner 78","Owner 79","Owner 80","Owner 81","Owner 82","Owner 83","Owner 84","Owner 85","Owner 86","Owner 87","Owner 88","Owner 89","Owner 90","Owner 91","Owner 92","Owner 93","Owner 94","Owner 95","Owner 96","Owner 97","Owner 98","Owner 99","Owner 100","Owner 101","Owner 102","Owner 103","Owner 104","Owner 105","Owner 106","Owner 107","Owner 108","Owner 109","Owner 110","Owner 111","Owner 112","Owner 113","Owner 114","Owner 115","Owner 116","Owner 117","Owner 118","Owner 119","Owner 120","Owner 121","Owner 122","Owner 123","Owner 124","Owner 125","Owner 126","Owner 127","Owner 128","Owner 129","Owner 130","Owner 131","Owner 132","Owner 133","Owner 134","Owner 135","Owner 136","Owner 137","Owner 138","Owner 139","Owner 140","Owner 141","Owner 142","Owner 143","Owner 144","Owner 145","Owner 146","Owner 147","Owner 148","Owner 149","Owner 150","Owner 151","Owner 152","Owner 153","Owner 154","Owner 155","Owner 156","Owner 157","Owner 158","Owner 159","Owner 160","Owner 161","Owner 162","Owner 163","Owner 164","Owner 165","Owner 166","Owner 167","Owner 168","Owner 169","Owner 170","Owner 171","Owner 172","Owner 173","Owner 174","Owner 175","Owner 176","Owner 177","Owner 178","Owner 179","Owner 180","Owner 181","Owner 182","Owner 183","Owner 184","Owner 185","Owner 186","Owner 187","Owner 188","Owner 189","Owner 190","Owner 191","Owner 192","Owner 193","Owner 194","Owner 195","Owner 196","Owner 197","Owner 198","Owner 199","Owner 200","Owner 201","Owner 202","Owner 203","Owner 204","Owner 205","Owner 206","Owner 207","Owner 208","Owner 209","Owner 210","Owner 211","Owner 212","Owner 213","Owner 214","Owner 215","Owner 216","Owner 217","Owner 218","Owner 219","Owner 220","Owner 221","Owner 222","Owner 223","Owner 224","Owner 225","Owner 226","Owner 227","Owner 228","Owner 229","Owner 230","Owner 231","Owner 232","Owner 233","Owner 234","Owner 235","Owner 236","Owner 237","Owner 238","Owner 239","Owner 240","Owner 241","Owner 242","Owner 243","Owner 244","Owner 245","Owner 246","Owner 247","Owner 248","Owner 249","Owner 250","Owner 251","Owner 252","Owner 253","Owner 254","Owner 255","Owner 256","Owner 257","Owner 258","Owner 259","Owner 260","Owner 261","Owner 262","Owner 263","Owner 264","Owner 265","Owner 266","Owner 267","Owner 268","Owner 269","Owner 270","Owner 271","Owner 272","Owner 273","Owner 274","Owner 275","Owner 276","Owner 277","Owner 278","Owner 279","Owner 280","Owner 281","Owner 282","Owner 283","Owner 284","Owner 285","Owner 286","Owner 287","Owner 288","Owner 289","Owner 290","Owner 291","Owner 292","Owner 293","Owner 294","Owner 295","Owner 296","Owner 297","Owner 298","Owner 299","Owner 300","Owner 301","Owner 302","Owner 303","Owner 304","Owner 305","Owner 306","Owner 307","Owner 308","Owner 309","Owner 310","Owner 311","Owner 312","Owner 313","Owner 314","Owner 315","Owner 316","Owner 317","Owner 318","Owner 319","Owner 320","Owner 321","Owner 322","Owner 323","Owner 324","Owner 325","Owner 326","Owner 327","Owner 328","Owner 329","Owner 330","Owner 331","Owner 332","Owner 333","Owner 334","Owner 335","Owner 336","Owner 337","Owner 338","Owner 339","Owner 340","Owner 341","Owner 342","Owner 343","Owner 344","Owner 345","Owner 346","Owner 347","Owner 348","Owner 349","Owner 350","Owner 351","Owner 352","Owner 353","Owner 354","Owner 355","Owner 356","Owner 357","Owner 358","Owner 359","Owner 360","Owner 361","Owner 362","Owner 363","Owner 364","Owner 365","Owner 366","Owner 367","Owner 368","Owner 369","Owner 370","Owner 371","Owner 372","Owner 373","Owner 374","Owner 375","Owner 376","Owner 377","Owner 378","Owner 379","Owner 380","Owner 381","Owner 382","Owner 383","Owner 384","Owner 385","Owner 386","Owner 387","Owner 388","Owner 389","Owner 390","Owner 391","Owner 392","Owner 393","Owner 394","Owner 395","Owner 396","Owner 397","Owner 398","Owner 399","Owner 400"};
const std::string townHp[20][20]={"THP1","THP2","THP3","THP4","THP5","THP6","THP7","THP8","THP9","THP10","THP11","THP12","THP13","THP14","THP15","THP16","THP17","THP18","THP19","THP20","THP21","THP22","THP23","THP24","THP25","THP26","THP27","THP28","THP29","THP30","THP31","THP32","THP33","THP34","THP35","THP36","THP37","THP38","THP39","THP40","THP41","THP42","THP43","THP44","THP45","THP46","THP47","THP48","THP49","THP50","THP51","THP52","THP53","THP54","THP55","THP56","THP57","THP58","THP59","THP60","THP61","THP62","THP63","THP64","THP65","THP66","THP67","THP68","THP69","THP70","THP71","THP72","THP73","THP74","THP75","THP76","THP77","THP78","THP79","THP80","THP81","THP82","THP83","THP84","THP85","THP86","THP87","THP88","THP89","THP90","THP91","THP92","THP93","THP94","THP95","THP96","THP97","THP98","THP99","THP100","THP101","THP102","THP103","THP104","THP105","THP106","THP107","THP108","THP109","THP110","THP111","THP112","THP113","THP114","THP115","THP116","THP117","THP118","THP119","THP120","THP121","THP122","THP123","THP124","THP125","THP126","THP127","THP128","THP129","THP130","THP131","THP132","THP133","THP134","THP135","THP136","THP137","THP138","THP139","THP140","THP141","THP142","THP143","THP144","THP145","THP146","THP147","THP148","THP149","THP150","THP151","THP152","THP153","THP154","THP155","THP156","THP157","THP158","THP159","THP160","THP161","THP162","THP163","THP164","THP165","THP166","THP167","THP168","THP169","THP170","THP171","THP172","THP173","THP174","THP175","THP176","THP177","THP178","THP179","THP180","THP181","THP182","THP183","THP184","THP185","THP186","THP187","THP188","THP189","THP190","THP191","THP192","THP193","THP194","THP195","THP196","THP197","THP198","THP199","THP200","THP201","THP202","THP203","THP204","THP205","THP206","THP207","THP208","THP209","THP210","THP211","THP212","THP213","THP214","THP215","THP216","THP217","THP218","THP219","THP220","THP221","THP222","THP223","THP224","THP225","THP226","THP227","THP228","THP229","THP230","THP231","THP232","THP233","THP234","THP235","THP236","THP237","THP238","THP239","THP240","THP241","THP242","THP243","THP244","THP245","THP246","THP247","THP248","THP249","THP250","THP251","THP252","THP253","THP254","THP255","THP256","THP257","THP258","THP259","THP260","THP261","THP262","THP263","THP264","THP265","THP266","THP267","THP268","THP269","THP270","THP271","THP272","THP273","THP274","THP275","THP276","THP277","THP278","THP279","THP280","THP281","THP282","THP283","THP284","THP285","THP286","THP287","THP288","THP289","THP290","THP291","THP292","THP293","THP294","THP295","THP296","THP297","THP298","THP299","THP300","THP301","THP302","THP303","THP304","THP305","THP306","THP307","THP308","THP309","THP310","THP311","THP312","THP313","THP314","THP315","THP316","THP317","THP318","THP319","THP320","THP321","THP322","THP323","THP324","THP325","THP326","THP327","THP328","THP329","THP330","THP331","THP332","THP333","THP334","THP335","THP336","THP337","THP338","THP339","THP340","THP341","THP342","THP343","THP344","THP345","THP346","THP347","THP348","THP349","THP350","THP351","THP352","THP353","THP354","THP355","THP356","THP357","THP358","THP359","THP360","THP361","THP362","THP363","THP364","THP365","THP366","THP367","THP368","THP369","THP370","THP371","THP372","THP373","THP374","THP375","THP376","THP377","THP378","THP379","THP380","THP381","THP382","THP383","THP384","THP385","THP386","THP387","THP388","THP389","THP390","THP391","THP392","THP393","THP394","THP395","THP396","THP397","THP398","THP399","THP400"};

CSaveData *savedata;

CSaveData::CSaveData(int stage){
	file.LoadMapSize();

	switch(stage){
	case 1:
		data=new CData("Kawachi2/Save1.txt");
		break;
		
	case 2:
		data=new CData("Kawachi2/Save2.txt");
		break;

	case 3:
		data=new CData("Kawachi2/Save3.txt");
		break;
	}
	
	data->ReadAll();

	turnNum=data->GetInt(turn);
	turnCountry=data->GetInt(turncountry);

	for(int i=1;i<=COUNTRY_NUM;i++){
		for(int n=1;n<=UNIT_NUM;n++){
			unitLocX[i][n]=data->GetInt(unitX[i][n]);
			unitLocY[i][n]=data->GetInt(unitY[i][n]);
			unitMoves[i][n]=data->GetInt(unitM[i][n]);
			unitPrepare[i][n]=data->GetInt(unitP[i][n]);
			unitType[i][n]=data->GetInt(unitT[i][n]);
			unitAttacked[i][n]=data->GetInt(unitA[i][n]);
			unitHP[i][n]=data->GetInt(unitH[i][n]);
		}

		countryMoney[i]=data->GetInt(money[i]);
	}

	for(int x=0;x<file.mapX[stage];x++){
		for(int y=0;y<file.mapY[stage];y++){
			townOwner[x][y]=data->GetInt(owner[x][y]);
			townHP[x][y]=data->GetInt(townHp[x][y]);
		}
	}
}

void CSaveData::Write(int stage){
	data->Set(turn,turnNum);
	data->Set(turncountry,turnCountry);

	for(int i=1;i<=COUNTRY_NUM;i++){
		for(int n=1;n<=UNIT_NUM;n++){
			data->Set(unitX[i][n],unitLocX[i][n]);
			data->Set(unitY[i][n],unitLocY[i][n]);
			data->Set(unitM[i][n],unitMoves[i][n]);
			data->Set(unitP[i][n],unitPrepare[i][n]);
			data->Set(unitT[i][n],unitType[i][n]);
			data->Set(unitA[i][n],unitAttacked[i][n]);
			data->Set(unitH[i][n],unitHP[i][n]);
		}

		data->Set(money[i],countryMoney[i]);
	}

	for(int x=0;x<file.mapX[stage];x++){
		for(int y=0;y<file.mapY[stage];y++){
			data->Set(owner[x][y],townOwner[x][y]);
			data->Set(townHp[x][y],townHP[x][y]);
		}
	}

	data->WriteAll();
}

void LoadSave(int stage){
	savedata=new CSaveData(stage);
}

void DeleteSave(){
	delete savedata;
	savedata=NULL;
}

void WriteSave(int stage){
	savedata->Write(stage);
}

int GetTurnNum(){
	return savedata->turnNum;
}

int GetTurnCountry(){
	return savedata->turnCountry;
}

int GetUnitX(int country, int unit){
	return savedata->unitLocX[country][unit];
}

int GetUnitY(int country, int unit){
	return savedata->unitLocY[country][unit];
}

int GetUnitMove(int country, int unit){
	return savedata->unitMoves[country][unit];
}

int GetUnitPrepare(int country, int unit){
	return savedata->unitPrepare[country][unit];
}

int GetUnitType(int country, int unit){
	return savedata->unitType[country][unit];
}

int GetUnitAttacked(int country, int unit){
	return savedata->unitAttacked[country][unit];
}

int GetUnitHP(int country, int unit){
	return savedata->unitHP[country][unit];
}

int GetCountryMoney(int country){
	return savedata->countryMoney[country];
}

int GetOwner(int x, int y){
	return savedata->townOwner[x][y];
}

int GetTHP(int x, int y){
	return savedata->townHP[x][y];
}

void SetTurnNum(int tNum){
	savedata->turnNum=tNum;
}

void SetTurnCountry(int tCountry){
	savedata->turnCountry=tCountry;
}

void SetUnitX(int country, int unit, int x){
	savedata->unitLocX[country][unit]=x;
}

void SetUnitY(int country, int unit, int y){
	savedata->unitLocY[country][unit]=y;
}

void SetUnitMove(int country, int unit, int moves){
	savedata->unitMoves[country][unit]=moves;
}

void SetUnitPrepare(int country, int unit, bool prepared){
	savedata->unitPrepare[country][unit]=prepared;
}

void SetUnitType(int country, int unit, int type){
	savedata->unitType[country][unit]=type;
}

void SetUnitAttacked(int country, int unit, bool attacked){
	savedata->unitAttacked[country][unit]=attacked;
}

void SetUnitHP(int country, int unit, int uHp){
	savedata->unitHP[country][unit]=uHp;
}

void SetCountryMoney(int country, int money){
	savedata->countryMoney[country]=money;
}

void SetTownOwner(int x, int y, int tOwner){
	savedata->townOwner[x][y]=tOwner;
}

void SetTownHP(int x, int y, int tHp){
	savedata->townHP[x][y]=tHp;
}
