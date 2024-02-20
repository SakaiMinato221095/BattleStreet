xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 219;
 -6.83156;-1.20830;14.94935;,
 -2.49751;-1.29783;17.32361;,
 -4.75029;5.13573;19.51688;,
 -9.81322;5.26964;15.55285;,
 0.46944;-1.32660;17.73304;,
 0.58151;5.04959;20.18360;,
 3.46113;-1.18216;16.84964;,
 5.82426;5.27051;19.25127;,
 7.68154;-0.99421;13.87569;,
 10.47772;5.56899;14.05174;,
 -4.84878;11.59820;19.80710;,
 -9.91170;11.73210;15.84307;,
 0.56401;11.47888;21.30486;,
 5.80673;11.69980;20.37253;,
 10.37923;12.03146;14.34196;,
 -4.94727;18.06066;20.09732;,
 -10.01019;18.19457;16.13326;,
 0.38449;17.97453;20.76400;,
 5.62724;18.19545;19.83171;,
 10.28074;18.49393;14.63214;,
 -3.51804;24.50550;19.21389;,
 -7.22556;24.64154;16.11020;,
 0.12210;24.50416;19.37247;,
 3.68275;24.67000;18.43143;,
 7.28758;24.85567;15.03654;,
 -4.95595;27.26819;13.47844;,
 -9.80135;24.74679;12.05964;,
 -0.02578;27.93679;14.51248;,
 4.90618;27.49835;13.26935;,
 9.34631;25.02923;10.64309;,
 -6.98381;27.42922;8.75778;,
 -9.97222;24.89876;8.76912;,
 -0.52295;29.53156;8.26019;,
 5.52820;27.78167;7.83459;,
 9.17541;25.18124;7.35256;,
 -9.97222;24.89876;8.76912;,
 -6.98381;27.42922;8.75778;,
 -5.63204;27.69438;3.74382;,
 -10.25785;25.03456;5.48643;,
 -0.52295;29.53156;8.26019;,
 -0.89812;28.48972;1.88322;,
 5.52820;27.78167;7.83459;,
 4.15886;27.96948;2.50843;,
 9.17541;25.18124;7.35256;,
 8.88977;25.31704;4.06988;,
 -5.01737;25.45049;-2.37096;,
 -8.25715;25.29184;1.25735;,
 -1.44755;25.49362;-3.22793;,
 2.21954;25.59245;-2.63875;,
 6.25599;25.50593;0.18366;,
 -6.57848;19.08896;-3.38971;,
 -11.04178;18.84484;1.28041;,
 -1.41916;19.11154;-5.20635;,
 3.92464;19.26872;-4.68323;,
 9.24919;19.14419;-0.22070;,
 -6.47999;12.62649;-3.67993;,
 -10.94326;12.38237;0.99020;,
 -1.35536;12.68880;-6.33076;,
 3.98844;12.84601;-5.80768;,
 9.34768;12.68173;-0.51092;,
 -6.38150;6.16403;-3.97011;,
 -10.84480;5.91994;0.69998;,
 -1.22218;6.18660;-5.78675;,
 4.12162;6.34379;-5.26367;,
 9.44617;6.21926;-0.80114;,
 -3.90199;-0.41255;-2.89746;,
 -7.86315;-0.55804;0.09647;,
 -1.03360;-0.37912;-3.90837;,
 2.06201;-0.30013;-3.29664;,
 6.64998;-0.34391;-0.97719;,
 -2.59488;-2.96243;3.77220;,
 -9.86386;-0.81532;4.32559;,
 -0.22657;-2.97791;3.51013;,
 2.15182;-2.89240;3.42105;,
 9.28377;-0.53284;2.90904;,
 -2.30988;-3.09785;7.04593;,
 -9.57826;-0.95112;7.60824;,
 0.07583;-3.73649;6.75813;,
 2.43682;-3.02785;6.69502;,
 9.56937;-0.66864;6.19172;,
 -9.57826;-0.95112;7.60824;,
 -2.30988;-3.09785;7.04593;,
 -2.13904;-3.24982;10.33597;,
 -9.40735;-1.10309;10.89876;,
 0.07583;-3.73649;6.75813;,
 0.22927;-3.26529;10.07388;,
 2.43682;-3.02785;6.69502;,
 2.60766;-3.17978;9.98481;,
 9.56937;-0.66864;6.19172;,
 9.74027;-0.82061;9.48225;,
 12.07995;6.03036;3.08512;,
 12.36559;5.89453;6.36777;,
 12.36559;5.89453;6.36777;,
 12.53645;5.74256;9.65833;,
 11.98146;12.49280;3.37531;,
 12.26709;12.35703;6.65799;,
 12.26709;12.35703;6.65799;,
 12.43797;12.20503;9.94851;,
 11.88297;18.95530;3.66553;,
 12.16861;18.81946;6.94821;,
 12.16861;18.81946;6.94821;,
 12.33948;18.66749;10.23874;,
 -12.84551;5.66261;4.92906;,
 -12.55987;5.52685;8.21175;,
 -12.38900;5.37485;11.50227;,
 -12.55987;5.52685;8.21175;,
 -12.94400;12.12509;5.21928;,
 -12.65836;11.98928;8.50196;,
 -12.48750;11.83732;11.79249;,
 -12.65836;11.98928;8.50196;,
 -13.04253;18.58756;5.50950;,
 -12.75689;18.45175;8.79218;,
 -12.58598;18.29978;12.08271;,
 -12.75689;18.45175;8.79218;,
 4.32406;0.41153;-2.89243;,
 2.92896;0.45056;-4.19219;,
 5.47048;3.50368;-5.19465;,
 8.03150;3.44183;-3.02637;,
 -0.23067;0.41780;-4.43225;,
 -0.36776;3.44319;-5.63824;,
 -3.32379;0.34458;-3.74720;,
 -6.08309;3.30785;-4.37244;,
 -4.51866;0.26170;-2.26312;,
 -8.30776;3.16491;-1.86353;,
 7.13484;8.00146;-5.75444;,
 10.47488;7.92435;-3.00579;,
 -0.49320;7.92243;-6.33401;,
 -7.96066;7.74560;-4.68015;,
 -10.87336;7.56256;-1.48647;,
 7.66869;13.25912;-5.78633;,
 11.28227;13.17666;-2.83387;,
 -0.58784;13.17361;-6.41364;,
 -8.67057;12.98224;-4.62353;,
 -11.82491;12.78504;-1.18939;,
 6.99071;18.47629;-5.28544;,
 10.33072;18.39919;-2.53679;,
 -0.63733;18.39726;-5.86501;,
 -8.10479;18.22044;-4.21116;,
 -11.01750;18.03736;-1.01748;,
 5.20413;22.85864;-4.32806;,
 7.76515;22.79680;-2.15973;,
 -0.63411;22.79816;-4.77161;,
 -6.34944;22.66285;-3.50583;,
 -8.57411;22.51991;-0.99693;,
 2.58095;25.73903;-3.05990;,
 3.97605;25.70004;-1.76018;,
 -0.57867;25.70631;-3.29996;,
 -3.67180;25.63309;-2.61491;,
 -4.86666;25.55018;-1.13084;,
 -0.08297;-0.70518;-2.62443;,
 -0.45964;26.66692;-1.39887;,
 10.47464;24.69589;-2.95578;,
 8.10654;28.88602;-2.04399;,
 8.49312;30.75737;2.55204;,
 14.76126;24.51193;1.93068;,
 -1.23723;31.82267;-3.76480;,
 -0.67293;33.58810;3.24563;,
 -10.14466;28.68008;-0.91955;,
 -9.75805;30.55140;3.67648;,
 -12.40745;24.51484;-1.67618;,
 -15.83160;24.21451;3.73479;,
 8.84637;30.57341;6.71354;,
 16.89242;24.35811;5.96562;,
 -0.31964;33.40417;7.40713;,
 -9.40476;30.36743;7.83798;,
 -17.25624;24.00041;8.02281;,
 16.89242;24.35811;5.96562;,
 8.84637;30.57341;6.71354;,
 9.94859;26.04291;20.24874;,
 15.67204;24.02439;12.97885;,
 -0.31964;33.40417;7.40713;,
 0.82378;25.88565;20.80853;,
 -9.40476;30.36743;7.83798;,
 -8.30254;25.83700;21.37318;,
 -17.25624;24.00041;8.02281;,
 -14.92091;23.72706;14.78296;,
 10.18649;16.83542;26.26390;,
 13.49941;17.98437;20.84895;,
 1.41227;21.53900;26.81249;,
 -7.21429;16.64390;27.32784;,
 -11.33831;17.77013;22.26771;,
 7.87813;0.28294;-4.15844;,
 2.48614;0.99750;-0.53370;,
 7.86340;4.97371;20.38670;,
 13.88046;4.84250;15.83426;,
 12.65294;0.10766;1.01375;,
 12.48283;12.37792;0.02917;,
 -0.43496;1.54518;0.29793;,
 2.78213;4.19996;23.13137;,
 1.14175;4.18124;23.08072;,
 -5.90917;4.78345;21.18978;,
 -3.43002;1.00058;-0.28713;,
 -9.18577;0.20048;-3.29293;,
 -12.42096;4.48119;17.35182;,
 -13.05271;-0.10692;2.47007;,
 -13.41097;12.02891;1.49311;,
 14.78405;-0.04616;5.04873;,
 19.36755;11.45585;5.22271;,
 -14.47738;-0.32099;6.75809;,
 -19.34855;10.88917;7.59921;,
 13.41303;-0.28812;9.96686;,
 14.78405;-0.04616;5.04873;,
 19.36755;11.45585;5.22271;,
 18.77930;10.11024;14.64334;,
 -14.47738;-0.32099;6.75809;,
 -12.29268;-0.50267;11.42317;,
 -17.26359;9.58846;16.82955;,
 -19.34855;10.88917;7.59921;,
 3.00508;-4.20878;17.40548;,
 12.72818;-0.52353;15.10377;,
 15.53200;8.92864;18.50874;,
 10.57191;6.60779;22.90257;,
 2.03614;6.35572;26.85754;,
 1.24297;-2.84424;18.62711;,
 1.68880;1.92759;23.79865;,
 -0.65399;-4.16745;17.49144;,
 -7.71328;6.33913;24.02671;,
 -10.76469;-0.71494;16.42680;,
 -13.34982;8.52204;20.20988;;
 
 198;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;3,2,10,11;,
 4;2,5,12,10;,
 4;5,7,13,12;,
 4;7,9,14,13;,
 4;11,10,15,16;,
 4;10,12,17,15;,
 4;12,13,18,17;,
 4;13,14,19,18;,
 4;16,15,20,21;,
 4;15,17,22,20;,
 4;17,18,23,22;,
 4;18,19,24,23;,
 4;21,20,25,26;,
 4;20,22,27,25;,
 4;22,23,28,27;,
 4;23,24,29,28;,
 4;26,25,30,31;,
 4;25,27,32,30;,
 4;27,28,33,32;,
 4;28,29,34,33;,
 4;35,36,37,38;,
 4;36,39,40,37;,
 4;39,41,42,40;,
 4;41,43,44,42;,
 4;38,37,45,46;,
 4;37,40,47,45;,
 4;40,42,48,47;,
 4;42,44,49,48;,
 4;46,45,50,51;,
 4;45,47,52,50;,
 4;47,48,53,52;,
 4;48,49,54,53;,
 4;51,50,55,56;,
 4;50,52,57,55;,
 4;52,53,58,57;,
 4;53,54,59,58;,
 4;56,55,60,61;,
 4;55,57,62,60;,
 4;57,58,63,62;,
 4;58,59,64,63;,
 4;61,60,65,66;,
 4;60,62,67,65;,
 4;62,63,68,67;,
 4;63,64,69,68;,
 4;66,65,70,71;,
 4;65,67,72,70;,
 4;67,68,73,72;,
 4;68,69,74,73;,
 4;71,70,75,76;,
 4;70,72,77,75;,
 4;72,73,78,77;,
 4;73,74,79,78;,
 4;80,81,82,83;,
 4;81,84,85,82;,
 4;84,86,87,85;,
 4;86,88,89,87;,
 4;83,82,1,0;,
 4;82,85,4,1;,
 4;85,87,6,4;,
 4;87,89,8,6;,
 4;74,69,64,90;,
 4;79,74,90,91;,
 4;89,88,92,93;,
 4;8,89,93,9;,
 4;90,64,59,94;,
 4;91,90,94,95;,
 4;93,92,96,97;,
 4;9,93,97,14;,
 4;94,59,54,98;,
 4;95,94,98,99;,
 4;97,96,100,101;,
 4;14,97,101,19;,
 4;98,54,49,44;,
 4;99,98,44,43;,
 4;101,100,34,29;,
 4;19,101,29,24;,
 4;66,71,102,61;,
 4;71,76,103,102;,
 4;80,83,104,105;,
 4;83,0,3,104;,
 4;61,102,106,56;,
 4;102,103,107,106;,
 4;105,104,108,109;,
 4;104,3,11,108;,
 4;56,106,110,51;,
 4;106,107,111,110;,
 4;109,108,112,113;,
 4;108,11,16,112;,
 4;51,110,38,46;,
 4;110,111,35,38;,
 4;113,112,26,31;,
 4;112,16,21,26;,
 4;114,115,116,117;,
 4;115,118,119,116;,
 4;118,120,121,119;,
 4;120,122,123,121;,
 4;117,116,124,125;,
 4;116,119,126,124;,
 4;119,121,127,126;,
 4;121,123,128,127;,
 4;125,124,129,130;,
 4;124,126,131,129;,
 4;126,127,132,131;,
 4;127,128,133,132;,
 4;130,129,134,135;,
 4;129,131,136,134;,
 4;131,132,137,136;,
 4;132,133,138,137;,
 4;135,134,139,140;,
 4;134,136,141,139;,
 4;136,137,142,141;,
 4;137,138,143,142;,
 4;140,139,144,145;,
 4;139,141,146,144;,
 4;141,142,147,146;,
 4;142,143,148,147;,
 3;115,114,149;,
 3;118,115,149;,
 3;120,118,149;,
 3;122,120,149;,
 3;145,144,150;,
 3;144,146,150;,
 3;146,147,150;,
 3;147,148,150;,
 4;151,152,153,154;,
 4;152,155,156,153;,
 4;155,157,158,156;,
 4;157,159,160,158;,
 4;154,153,161,162;,
 4;153,156,163,161;,
 4;156,158,164,163;,
 4;158,160,165,164;,
 4;166,167,168,169;,
 4;167,170,171,168;,
 4;170,172,173,171;,
 4;172,174,175,173;,
 4;169,168,176,177;,
 4;168,171,178,176;,
 4;171,173,179,178;,
 4;173,175,180,179;,
 4;181,182,183,184;,
 4;185,181,184,186;,
 4;182,187,188,183;,
 3;188,187,189;,
 3;189,187,190;,
 3;187,191,190;,
 4;191,192,193,190;,
 4;192,194,195,193;,
 4;196,185,186,197;,
 4;194,198,199,195;,
 4;200,201,202,203;,
 4;204,205,206,207;,
 4;208,209,210,211;,
 4;209,200,203,210;,
 3;211,212,208;,
 3;208,212,213;,
 3;212,214,213;,
 4;215,213,214,216;,
 4;205,217,218,206;,
 4;217,215,216,218;,
 4;184,183,152,151;,
 4;186,184,151,154;,
 3;183,188,152;,
 3;188,189,152;,
 3;189,155,152;,
 4;197,186,154,162;,
 4;203,202,166,169;,
 4;211,210,177,176;,
 4;210,203,169,177;,
 4;212,211,176,178;,
 4;189,190,157,155;,
 4;190,193,159,157;,
 4;193,195,160,159;,
 4;195,199,165,160;,
 4;207,206,175,174;,
 3;212,178,214;,
 3;214,178,216;,
 3;178,179,216;,
 4;206,218,180,175;,
 4;218,216,179,180;,
 3;201,200,185;,
 3;200,209,185;,
 3;209,208,185;,
 3;185,208,181;,
 3;181,208,182;,
 3;208,213,182;,
 3;182,213,187;,
 3;213,215,187;,
 3;215,217,187;,
 3;187,217,191;,
 3;191,217,192;,
 3;192,217,194;,
 3;217,205,194;,
 3;205,198,194;;
 
 MeshMaterialList {
  2;
  198;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\UV\\enemy_boss_000.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "enemy_boss_000.png";
   }
  }
 }
 MeshNormals {
  223;
  -0.553995;-0.639061;0.533564;,
  -0.246666;-0.753554;0.609353;,
  0.048326;-0.750329;0.659296;,
  0.338494;-0.752369;0.565121;,
  0.636187;-0.625140;0.452179;,
  -0.712148;-0.224272;0.665243;,
  -0.377928;-0.231778;0.896353;,
  0.021850;-0.258541;0.965753;,
  0.476915;-0.263319;0.838579;,
  0.811144;-0.213749;0.544387;,
  -0.740811;-0.041398;0.670436;,
  -0.418126;-0.047760;0.907133;,
  -0.010773;-0.045628;0.998900;,
  0.506455;-0.030926;0.861712;,
  0.845439;-0.011085;0.533957;,
  -0.734293;0.131190;0.666035;,
  -0.391072;0.104792;0.914375;,
  0.023957;0.131511;0.991025;,
  0.480445;0.175600;0.859266;,
  0.816400;0.180878;0.548428;,
  -0.644363;0.486985;0.589612;,
  -0.346324;0.574418;0.741690;,
  0.042752;0.570845;0.819944;,
  0.421563;0.576778;0.699722;,
  0.701003;0.493895;0.514454;,
  -0.723265;0.619853;0.304418;,
  -0.355277;0.872350;0.335832;,
  0.003332;0.928501;0.371315;,
  0.377269;0.875030;0.303299;,
  0.745951;0.627127;0.224209;,
  -0.777614;0.623405;0.081749;,
  -0.427848;0.901165;0.069627;,
  -0.023745;0.998685;0.045437;,
  0.387895;0.921603;0.013607;,
  0.755588;0.654620;-0.023665;,
  -0.755775;0.637152;-0.151136;,
  -0.399479;0.893402;-0.205547;,
  -0.045110;0.956989;-0.286597;,
  0.339217;0.899128;-0.276587;,
  0.709871;0.647958;-0.276105;,
  -0.720916;0.520375;-0.457700;,
  -0.466214;0.622562;-0.628538;,
  -0.074296;0.638243;-0.766242;,
  0.337778;0.629367;-0.699859;,
  0.622847;0.532404;-0.573243;,
  -0.817564;0.174404;-0.548792;,
  -0.544812;0.170789;-0.820982;,
  -0.120320;0.214730;-0.969234;,
  0.380498;0.244370;-0.891911;,
  0.727350;0.225036;-0.648321;,
  -0.824260;0.012858;-0.566065;,
  -0.571633;0.027350;-0.820054;,
  -0.156131;0.041211;-0.986876;,
  0.406381;0.047229;-0.912482;,
  0.755959;0.040869;-0.653342;,
  -0.797948;-0.159409;-0.581264;,
  -0.532402;-0.147266;-0.833583;,
  -0.121418;-0.172559;-0.977487;,
  0.377504;-0.178380;-0.908665;,
  0.719826;-0.151957;-0.677318;,
  -0.631949;-0.581115;-0.512783;,
  -0.359017;-0.690580;-0.627858;,
  -0.053423;-0.690806;-0.721064;,
  0.268523;-0.691117;-0.671009;,
  0.561370;-0.569860;-0.600103;,
  -0.639677;-0.748159;-0.176268;,
  -0.190464;-0.964335;-0.183795;,
  -0.001936;-0.970342;-0.241728;,
  0.190468;-0.957075;-0.218469;,
  0.628229;-0.724987;-0.282352;,
  -0.653343;-0.756963;0.012237;,
  -0.211999;-0.976842;-0.028935;,
  0.011798;-0.998858;-0.046291;,
  0.236123;-0.969888;-0.059690;,
  0.673879;-0.734610;-0.078965;,
  -0.612503;-0.766805;0.191962;,
  -0.162105;-0.979244;0.121664;,
  0.026529;-0.987984;0.152264;,
  0.208186;-0.972425;0.105111;,
  0.656728;-0.744112;0.122495;,
  0.925686;-0.170487;-0.337696;,
  0.978931;-0.189408;-0.076281;,
  0.963641;-0.196506;0.181055;,
  0.942354;0.029331;-0.333329;,
  0.997485;0.018277;-0.068476;,
  0.981319;0.006321;0.192282;,
  0.919508;0.231205;-0.317884;,
  0.971949;0.228048;-0.057520;,
  0.957104;0.211923;0.197585;,
  -0.960958;-0.206486;-0.184184;,
  -0.972750;-0.224556;0.057727;,
  -0.928945;-0.231087;0.289240;,
  -0.984208;-0.007059;-0.176873;,
  -0.997485;-0.018279;0.068477;,
  -0.952484;-0.028137;0.303287;,
  -0.966412;0.197056;-0.164973;,
  -0.978232;0.192944;0.076388;,
  -0.934669;0.180230;0.306447;,
  0.378360;-0.812202;-0.444039;,
  0.229539;-0.748001;-0.622741;,
  -0.043442;-0.643987;-0.763802;,
  -0.290045;-0.756813;-0.585755;,
  -0.409822;-0.825567;-0.387925;,
  0.564211;-0.480820;-0.671176;,
  0.334810;-0.388536;-0.858453;,
  -0.063970;-0.265236;-0.962059;,
  -0.439687;-0.401667;-0.803330;,
  -0.637024;-0.501185;-0.585674;,
  0.622246;-0.196195;-0.757837;,
  0.365672;-0.146061;-0.919212;,
  -0.069275;-0.085914;-0.993891;,
  -0.486996;-0.160514;-0.858528;,
  -0.716304;-0.218885;-0.662569;,
  0.634075;0.043294;-0.772059;,
  0.371207;0.046630;-0.927379;,
  -0.071655;0.043630;-0.996475;,
  -0.500123;0.031865;-0.865368;,
  -0.738092;0.020040;-0.674402;,
  0.615694;0.280141;-0.736506;,
  0.360394;0.237599;-0.902033;,
  -0.072831;0.172443;-0.982323;,
  -0.492275;0.223149;-0.841350;,
  -0.722859;0.257456;-0.641242;,
  0.549971;0.554182;-0.624831;,
  0.322958;0.472736;-0.819890;,
  -0.072413;0.348279;-0.934590;,
  -0.451537;0.459612;-0.764769;,
  -0.651267;0.533825;-0.539334;,
  0.355371;0.858712;-0.369222;,
  0.208145;0.806671;-0.553135;,
  -0.062049;0.708215;-0.703265;,
  -0.311437;0.797871;-0.516148;,
  -0.432817;0.845360;-0.313107;,
  -0.012721;-0.917619;-0.397257;,
  -0.038403;0.948746;-0.313697;,
  -0.328373;0.921913;-0.205541;,
  -0.048321;0.984055;-0.171174;,
  -0.017333;0.989298;-0.144878;,
  -0.063983;0.980089;-0.187965;,
  0.272612;0.932029;-0.238757;,
  -0.573003;0.793250;-0.205967;,
  0.512807;0.814029;-0.272738;,
  0.908750;-0.294902;-0.295307;,
  -0.932463;-0.328922;-0.149411;,
  0.873042;-0.438906;0.212507;,
  -0.810860;-0.472235;0.345688;,
  0.632548;-0.701180;0.328982;,
  0.219873;-0.920523;0.322945;,
  -0.100838;-0.654150;0.749613;,
  -0.334818;-0.598112;0.728120;,
  -0.620570;-0.531852;0.576217;,
  0.662575;0.596847;-0.452514;,
  0.491884;0.773842;-0.399021;,
  0.494422;0.836277;-0.237039;,
  0.733515;0.515376;-0.443106;,
  -0.038302;0.950538;-0.308237;,
  -0.023980;0.990808;-0.133132;,
  -0.566399;0.764436;-0.307945;,
  -0.545047;0.825217;-0.148122;,
  -0.736062;0.588191;-0.335028;,
  -0.807248;0.497707;-0.317237;,
  0.440031;0.890699;0.114138;,
  0.841020;0.523722;-0.135645;,
  0.003036;0.972916;0.231138;,
  -0.442971;0.877023;0.186029;,
  -0.868610;0.495496;0.000781;,
  0.455442;0.745691;0.486330;,
  0.840016;0.397768;0.368991;,
  0.026472;0.818396;0.574044;,
  -0.409926;0.727106;0.550705;,
  -0.791167;0.363186;0.492088;,
  0.556295;0.237429;0.796344;,
  0.805461;0.141640;0.575474;,
  0.113842;0.174771;0.978006;,
  -0.552615;0.334149;0.763519;,
  -0.723884;0.109652;0.681153;,
  -0.022893;0.990762;-0.133669;,
  0.953397;-0.064649;-0.294713;,
  0.944576;-0.145276;0.294400;,
  0.512040;-0.360377;0.779707;,
  0.790770;-0.250068;0.558702;,
  0.207548;-0.492518;0.845192;,
  -0.003575;0.986007;-0.166666;,
  -0.984766;-0.100672;-0.141779;,
  -0.880959;-0.180959;0.437224;,
  0.997922;-0.051981;-0.038066;,
  -0.254899;-0.382067;0.888286;,
  -0.696633;-0.277576;0.661554;,
  0.054670;0.991448;-0.118498;,
  0.749487;-0.123919;-0.650318;,
  0.758956;-0.009331;-0.651075;,
  -0.837218;-0.151697;-0.525408;,
  -0.850574;-0.038468;-0.524446;,
  0.893936;-0.423244;-0.147454;,
  -0.129455;-0.409988;0.902857;,
  -0.521152;-0.418541;-0.743790;,
  -0.486227;-0.607809;-0.627815;,
  -0.262595;-0.678152;-0.686406;,
  -0.330337;-0.272813;-0.903576;,
  -0.126355;-0.694799;-0.708018;,
  0.003567;-0.700944;-0.713207;,
  -0.009537;-0.692657;-0.721204;,
  0.362566;-0.617697;-0.697851;,
  0.436583;-0.393350;-0.809118;,
  0.212565;-0.256420;-0.942902;,
  -0.984693;-0.039957;0.169656;,
  0.229383;-0.306999;0.923653;,
  0.013708;-0.998878;-0.045320;,
  0.010566;-0.998929;-0.045055;,
  0.129958;-0.988546;-0.076735;,
  0.007423;-0.998969;-0.044790;,
  -0.075838;-0.972608;-0.219731;,
  -0.414403;-0.882460;-0.222565;,
  -0.679062;-0.710016;-0.186416;,
  -0.473074;-0.857411;-0.202604;,
  0.085670;-0.974167;-0.208949;,
  0.208684;-0.928888;-0.305969;,
  0.016044;-0.995637;-0.091924;,
  0.168767;-0.985284;-0.027069;,
  0.083427;-0.995729;-0.039544;,
  0.011149;-0.998916;-0.045197;,
  0.010875;-0.998924;-0.045078;,
  0.013694;-0.998879;-0.045315;;
  198;
  4;0,1,6,5;,
  4;1,2,7,6;,
  4;2,3,8,7;,
  4;3,4,9,8;,
  4;5,6,11,10;,
  4;6,7,12,11;,
  4;7,8,13,12;,
  4;8,9,14,13;,
  4;10,11,16,15;,
  4;11,12,17,16;,
  4;12,13,18,17;,
  4;13,14,19,18;,
  4;15,16,21,20;,
  4;16,17,22,21;,
  4;17,18,23,22;,
  4;18,19,24,23;,
  4;20,21,26,25;,
  4;21,22,27,26;,
  4;22,23,28,27;,
  4;23,24,29,28;,
  4;25,26,31,30;,
  4;26,27,32,31;,
  4;27,28,33,32;,
  4;28,29,34,33;,
  4;30,31,36,35;,
  4;31,32,37,36;,
  4;32,33,38,37;,
  4;33,34,39,38;,
  4;35,36,41,40;,
  4;36,37,42,41;,
  4;37,38,43,42;,
  4;38,39,44,43;,
  4;40,41,46,45;,
  4;41,42,47,46;,
  4;42,43,48,47;,
  4;43,44,49,48;,
  4;45,46,51,50;,
  4;46,47,52,51;,
  4;47,48,53,52;,
  4;48,49,54,53;,
  4;50,51,56,55;,
  4;51,52,57,56;,
  4;52,53,58,57;,
  4;53,54,59,58;,
  4;55,56,61,60;,
  4;56,57,62,61;,
  4;57,58,63,62;,
  4;58,59,64,63;,
  4;60,61,66,65;,
  4;61,62,67,66;,
  4;62,63,68,67;,
  4;63,64,69,68;,
  4;65,66,71,70;,
  4;66,67,72,71;,
  4;67,68,73,72;,
  4;68,69,74,73;,
  4;70,71,76,75;,
  4;71,72,77,76;,
  4;72,73,78,77;,
  4;73,74,79,78;,
  4;75,76,1,0;,
  4;76,77,2,1;,
  4;77,78,3,2;,
  4;78,79,4,3;,
  4;69,64,59,80;,
  4;74,69,80,81;,
  4;79,74,81,82;,
  4;4,79,82,9;,
  4;80,59,54,83;,
  4;81,80,83,84;,
  4;82,81,84,85;,
  4;9,82,85,14;,
  4;83,54,49,86;,
  4;84,83,86,87;,
  4;85,84,87,88;,
  4;14,85,88,19;,
  4;86,49,44,39;,
  4;87,86,39,34;,
  4;88,87,34,29;,
  4;19,88,29,24;,
  4;60,65,89,55;,
  4;65,70,90,89;,
  4;70,75,91,90;,
  4;75,0,5,91;,
  4;55,89,92,50;,
  4;89,90,93,92;,
  4;90,91,94,93;,
  4;91,5,10,94;,
  4;50,92,95,45;,
  4;92,93,96,95;,
  4;93,94,97,96;,
  4;94,10,15,97;,
  4;45,95,35,40;,
  4;95,96,30,35;,
  4;96,97,25,30;,
  4;97,15,20,25;,
  4;98,99,104,103;,
  4;99,100,105,104;,
  4;100,101,106,105;,
  4;101,102,107,106;,
  4;103,104,109,108;,
  4;104,105,110,109;,
  4;105,106,111,110;,
  4;106,107,112,111;,
  4;108,109,114,113;,
  4;109,110,115,114;,
  4;110,111,116,115;,
  4;111,112,117,116;,
  4;113,114,119,118;,
  4;114,115,120,119;,
  4;115,116,121,120;,
  4;116,117,122,121;,
  4;118,119,124,123;,
  4;119,120,125,124;,
  4;120,121,126,125;,
  4;121,122,127,126;,
  4;123,124,129,128;,
  4;124,125,130,129;,
  4;125,126,131,130;,
  4;126,127,132,131;,
  3;99,98,133;,
  3;100,99,133;,
  3;101,100,133;,
  3;102,101,133;,
  3;128,129,134;,
  3;129,130,134;,
  3;130,131,134;,
  3;131,132,134;,
  4;151,152,153,154;,
  4;152,155,156,153;,
  4;155,157,158,156;,
  4;157,159,160,158;,
  4;154,153,161,162;,
  4;153,156,163,161;,
  4;156,158,164,163;,
  4;158,160,165,164;,
  4;162,161,166,167;,
  4;161,163,168,166;,
  4;163,164,169,168;,
  4;164,165,170,169;,
  4;167,166,171,172;,
  4;166,168,173,171;,
  4;168,169,174,173;,
  4;169,170,175,174;,
  4;135,136,136,135;,
  4;140,135,135,140;,
  4;136,137,176,136;,
  3;176,137,188;,
  3;188,137,182;,
  3;137,138,182;,
  4;138,139,139,182;,
  4;139,141,141,139;,
  4;142,189,190,177;,
  4;191,143,183,192;,
  4;144,142,177,178;,
  4;143,145,184,183;,
  4;147,146,180,179;,
  4;146,144,178,180;,
  3;179,181,147;,
  3;147,181,148;,
  3;185,185,193;,
  4;149,148,194,186;,
  4;145,150,187,184;,
  4;150,149,186,187;,
  4;195,196,197,195;,
  4;198,195,195,198;,
  3;196,199,197;,
  3;199,200,197;,
  3;200,201,197;,
  4;177,190,154,162;,
  4;178,177,162,167;,
  4;179,180,172,171;,
  4;180,178,167,172;,
  4;181,179,171,173;,
  4;200,202,202,201;,
  4;202,203,203,202;,
  4;203,204,204,203;,
  4;192,183,165,160;,
  4;183,184,170,165;,
  3;205,205,205;,
  3;194,173,186;,
  3;173,206,186;,
  4;184,187,175,170;,
  4;187,186,174,175;,
  3;207,208,209;,
  3;208,210,209;,
  3;146,147,209;,
  3;209,147,211;,
  3;211,147,212;,
  3;213,214,212;,
  3;212,214,215;,
  3;193,216,215;,
  3;216,217,215;,
  3;215,217,218;,
  3;218,217,219;,
  3;219,217,220;,
  3;217,221,220;,
  3;221,222,220;;
 }
 MeshTextureCoords {
  219;
  0.440790;0.953410;,
  0.408940;0.953660;,
  0.426530;0.915790;,
  0.463090;0.915640;,
  0.386470;0.953950;,
  0.386120;0.916540;,
  0.363080;0.953580;,
  0.345470;0.915920;,
  0.329150;0.953600;,
  0.307000;0.915910;,
  0.426610;0.878410;,
  0.463170;0.878260;,
  0.386030;0.879150;,
  0.345380;0.878530;,
  0.307070;0.878540;,
  0.426680;0.841040;,
  0.463240;0.840890;,
  0.386260;0.841790;,
  0.345620;0.841170;,
  0.307140;0.841160;,
  0.414430;0.804190;,
  0.441090;0.803920;,
  0.386670;0.804450;,
  0.358890;0.804020;,
  0.329440;0.804110;,
  0.421950;0.789620;,
  0.458570;0.804150;,
  0.384710;0.785890;,
  0.346350;0.789130;,
  0.311270;0.804410;,
  0.434940;0.789750;,
  0.458140;0.804110;,
  0.384940;0.778260;,
  0.338620;0.788950;,
  0.310780;0.804370;,
  0.209070;0.799790;,
  0.185820;0.785410;,
  0.172680;0.785280;,
  0.209450;0.799830;,
  0.135740;0.773900;,
  0.135270;0.781540;,
  0.089330;0.784610;,
  0.096900;0.784790;,
  0.061440;0.800050;,
  0.061820;0.800090;,
  0.164930;0.799880;,
  0.191770;0.799600;,
  0.137080;0.800140;,
  0.109270;0.799710;,
  0.079870;0.799800;,
  0.177170;0.836790;,
  0.213970;0.836630;,
  0.136610;0.837540;,
  0.095900;0.836920;,
  0.057530;0.836910;,
  0.177090;0.874220;,
  0.213890;0.874060;,
  0.136340;0.874950;,
  0.095630;0.874330;,
  0.057450;0.874340;,
  0.177020;0.911650;,
  0.213820;0.911490;,
  0.136460;0.912400;,
  0.095760;0.911780;,
  0.057380;0.911770;,
  0.159450;0.949580;,
  0.191470;0.949330;,
  0.136900;0.949870;,
  0.113490;0.949500;,
  0.079580;0.949520;,
  0.153400;0.962690;,
  0.209150;0.949560;,
  0.135100;0.963030;,
  0.116800;0.962750;,
  0.061530;0.949820;,
  0.153020;0.962650;,
  0.208770;0.949520;,
  0.134650;0.966600;,
  0.116420;0.962710;,
  0.061150;0.949770;,
  0.457850;0.953600;,
  0.402190;0.966710;,
  0.402640;0.966750;,
  0.458280;0.953640;,
  0.383850;0.970660;,
  0.384380;0.967100;,
  0.365660;0.966780;,
  0.366130;0.966820;,
  0.310490;0.953860;,
  0.310980;0.953900;,
  0.039330;0.912060;,
  0.038950;0.912020;,
  0.288330;0.916160;,
  0.288830;0.916200;,
  0.039400;0.874630;,
  0.039020;0.874590;,
  0.288400;0.878790;,
  0.288910;0.878830;,
  0.039480;0.837200;,
  0.039100;0.837160;,
  0.288480;0.841420;,
  0.288980;0.841460;,
  0.231500;0.911730;,
  0.231120;0.911690;,
  0.480580;0.915870;,
  0.480160;0.915830;,
  0.231580;0.874300;,
  0.231200;0.874260;,
  0.480650;0.878500;,
  0.480230;0.878460;,
  0.231650;0.836870;,
  0.231270;0.836830;,
  0.480730;0.841130;,
  0.480300;0.841090;,
  0.179430;0.693840;,
  0.202360;0.693840;,
  0.155420;0.647520;,
  0.113040;0.647520;,
  0.257740;0.693840;,
  0.257740;0.647520;,
  0.313110;0.693840;,
  0.360050;0.647520;,
  0.336050;0.693840;,
  0.402430;0.647520;,
  0.124060;0.578190;,
  0.068680;0.578190;,
  0.257740;0.578190;,
  0.391420;0.578190;,
  0.446790;0.578190;,
  0.113040;0.496410;,
  0.053110;0.496410;,
  0.257740;0.496410;,
  0.402430;0.496410;,
  0.462370;0.496410;,
  0.124060;0.414630;,
  0.068680;0.414630;,
  0.257740;0.414630;,
  0.391420;0.414630;,
  0.446790;0.414630;,
  0.155420;0.345300;,
  0.113040;0.345300;,
  0.257740;0.345300;,
  0.360050;0.345300;,
  0.402430;0.345300;,
  0.202360;0.298980;,
  0.179430;0.298980;,
  0.257740;0.298980;,
  0.313110;0.298980;,
  0.336050;0.298980;,
  0.257740;0.710110;,
  0.257740;0.282710;,
  0.557910;0.297870;,
  0.588430;0.294130;,
  0.588080;0.280910;,
  0.540760;0.297910;,
  0.622630;0.293940;,
  0.622260;0.280730;,
  0.656790;0.293750;,
  0.656430;0.280540;,
  0.686990;0.297120;,
  0.703670;0.297100;,
  0.587870;0.280920;,
  0.533590;0.297920;,
  0.622040;0.280740;,
  0.656220;0.280550;,
  0.710420;0.297110;,
  0.793580;0.298080;,
  0.847750;0.281120;,
  0.847510;0.281130;,
  0.800280;0.298090;,
  0.881860;0.280930;,
  0.881620;0.280940;,
  0.915970;0.280740;,
  0.915730;0.280750;,
  0.970060;0.297280;,
  0.962870;0.297290;,
  0.847200;0.294350;,
  0.816950;0.298080;,
  0.881280;0.294170;,
  0.915410;0.293980;,
  0.945770;0.297330;,
  0.557910;0.297870;,
  0.588430;0.294130;,
  0.588430;0.294130;,
  0.557910;0.297870;,
  0.540760;0.297910;,
  0.540760;0.297910;,
  0.622630;0.293940;,
  0.622630;0.293940;,
  0.622630;0.293940;,
  0.656790;0.293750;,
  0.656790;0.293750;,
  0.686990;0.297120;,
  0.686990;0.297120;,
  0.703670;0.297100;,
  0.703670;0.297100;,
  0.533590;0.297920;,
  0.533590;0.297920;,
  0.710420;0.297110;,
  0.710420;0.297110;,
  0.800280;0.298090;,
  0.793580;0.298080;,
  0.793580;0.298080;,
  0.800280;0.298090;,
  0.970060;0.297280;,
  0.962870;0.297290;,
  0.962870;0.297290;,
  0.970060;0.297280;,
  0.847200;0.294350;,
  0.816950;0.298080;,
  0.816950;0.298080;,
  0.847200;0.294350;,
  0.881280;0.294170;,
  0.881280;0.294170;,
  0.881280;0.294170;,
  0.915410;0.293980;,
  0.915410;0.293980;,
  0.945770;0.297330;,
  0.945770;0.297330;;
 }
}
