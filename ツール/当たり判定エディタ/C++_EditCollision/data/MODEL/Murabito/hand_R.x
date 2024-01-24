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
 84;
 28.35260;-1.79690;0.73510;,
 29.44100;-3.31300;1.38500;,
 29.47010;-1.33980;3.28730;,
 28.36830;-0.72910;1.76470;,
 29.49420;1.40070;3.23710;,
 28.38140;0.75400;1.73760;,
 29.49910;3.30310;1.26380;,
 28.38410;1.78360;0.66960;,
 29.48210;3.25310;-1.47670;,
 28.37480;1.75650;-0.81360;,
 29.45300;1.27990;-3.37900;,
 28.35910;0.68870;-1.84310;,
 29.42890;-1.46060;-3.32890;,
 28.34610;-0.79440;-1.81590;,
 29.42400;-3.36300;-1.35550;,
 28.34340;-1.82400;-0.74800;,
 31.07770;-4.33400;1.81360;,
 31.11570;-1.75600;4.29920;,
 31.14720;1.82460;4.23360;,
 31.15370;4.31020;1.65540;,
 31.13140;4.24490;-1.92530;,
 31.09340;1.66680;-4.41080;,
 31.06200;-1.91380;-4.34530;,
 31.05550;-4.39940;-1.76700;,
 33.01360;-4.70470;1.95600;,
 33.05470;-1.91420;4.64630;,
 33.08880;1.96140;4.57530;,
 33.09580;4.65180;1.78460;,
 33.07170;4.58110;-2.09100;,
 33.03060;1.79060;-4.78140;,
 32.99650;-2.08500;-4.71040;,
 32.98950;-4.77540;-1.91970;,
 34.95390;-4.36850;1.79020;,
 34.99190;-1.79040;4.27570;,
 35.02330;1.79010;4.21020;,
 35.02990;4.27580;1.63190;,
 35.00760;4.21040;-1.94870;,
 34.96960;1.63230;-4.43430;,
 34.93810;-1.94830;-4.36870;,
 34.93160;-4.43380;-1.79050;,
 36.60320;-3.37670;1.34160;,
 36.63230;-1.40350;3.24390;,
 36.65640;1.33690;3.19370;,
 36.66140;3.23930;1.22050;,
 36.64430;3.18930;-1.52010;,
 36.61520;1.21610;-3.42240;,
 36.59120;-1.52430;-3.37220;,
 36.58620;-3.42670;-1.39890;,
 37.71050;-1.88020;0.67850;,
 37.72620;-0.81230;1.70800;,
 37.73920;0.67080;1.68090;,
 37.74190;1.70040;0.61290;,
 37.73270;1.67330;-0.87020;,
 37.71700;0.60550;-1.89980;,
 37.70390;-0.87770;-1.87260;,
 37.70120;-1.90720;-0.80470;,
 27.97820;-0.01680;-0.03690;,
 38.10710;-0.10690;-0.09820;,
 29.81960;-2.77530;-2.87460;,
 15.48710;-2.76050;-3.10260;,
 15.50330;-0.00140;-3.93950;,
 29.83570;-0.01620;-3.71160;,
 15.49210;2.74410;-3.05920;,
 29.82460;2.72940;-2.83140;,
 -0.25050;-2.74430;-3.35280;,
 -0.23430;0.01480;-4.18980;,
 -0.24540;2.76040;-3.30950;,
 -0.30220;-3.62410;-0.15170;,
 -0.29900;-0.01710;-0.12330;,
 -0.29570;3.58980;-0.09490;,
 -0.34250;-2.78970;2.43370;,
 -0.35360;-0.04410;3.30910;,
 -0.33750;2.71500;2.47700;,
 15.39510;-2.80590;2.68390;,
 15.38400;-0.06030;3.55930;,
 15.40000;2.69870;2.72730;,
 29.72750;-2.82070;2.91180;,
 29.71640;-0.07510;3.78730;,
 29.73250;2.68390;2.95520;,
 29.76780;-3.65510;0.32650;,
 29.77110;-0.04810;0.35480;,
 29.77430;3.55880;0.38320;,
 15.44180;3.57360;0.15530;,
 15.43530;-3.64030;0.09860;;
 
 88;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;5,4,6,7;,
 4;7,6,8,9;,
 4;9,8,10,11;,
 4;11,10,12,13;,
 4;13,12,14,15;,
 4;15,14,1,0;,
 4;1,16,17,2;,
 4;2,17,18,4;,
 4;4,18,19,6;,
 4;6,19,20,8;,
 4;8,20,21,10;,
 4;10,21,22,12;,
 4;12,22,23,14;,
 4;14,23,16,1;,
 4;16,24,25,17;,
 4;17,25,26,18;,
 4;18,26,27,19;,
 4;19,27,28,20;,
 4;20,28,29,21;,
 4;21,29,30,22;,
 4;22,30,31,23;,
 4;23,31,24,16;,
 4;24,32,33,25;,
 4;25,33,34,26;,
 4;26,34,35,27;,
 4;27,35,36,28;,
 4;28,36,37,29;,
 4;29,37,38,30;,
 4;30,38,39,31;,
 4;31,39,32,24;,
 4;32,40,41,33;,
 4;33,41,42,34;,
 4;34,42,43,35;,
 4;35,43,44,36;,
 4;36,44,45,37;,
 4;37,45,46,38;,
 4;38,46,47,39;,
 4;39,47,40,32;,
 4;40,48,49,41;,
 4;41,49,50,42;,
 4;42,50,51,43;,
 4;43,51,52,44;,
 4;44,52,53,45;,
 4;45,53,54,46;,
 4;46,54,55,47;,
 4;47,55,48,40;,
 3;3,56,0;,
 3;5,56,3;,
 3;7,56,5;,
 3;9,56,7;,
 3;11,56,9;,
 3;13,56,11;,
 3;15,56,13;,
 3;0,56,15;,
 3;48,57,49;,
 3;49,57,50;,
 3;50,57,51;,
 3;51,57,52;,
 3;52,57,53;,
 3;53,57,54;,
 3;54,57,55;,
 3;55,57,48;,
 4;58,59,60,61;,
 4;61,60,62,63;,
 4;59,64,65,60;,
 4;60,65,66,62;,
 4;64,67,68,65;,
 4;65,68,69,66;,
 4;67,70,71,68;,
 4;68,71,72,69;,
 4;70,73,74,71;,
 4;71,74,75,72;,
 4;73,76,77,74;,
 4;74,77,78,75;,
 4;76,79,80,77;,
 4;77,80,81,78;,
 4;79,58,61,80;,
 4;80,61,63,81;,
 4;81,82,75,78;,
 4;63,62,82,81;,
 4;82,69,72,75;,
 4;62,66,69,82;,
 4;76,73,83,79;,
 4;79,83,59,58;,
 4;73,70,67,83;,
 4;83,67,64,59;;
 
 MeshMaterialList {
  4;
  88;
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\murabitoUV.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\murabitoUV.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\murabitoUV.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\murabitoUV.png";
   }
  }
 }
 MeshNormals {
  100;
  -0.926866;-0.340688;0.157645;,
  -0.923778;-0.130974;0.359835;,
  -0.921211;0.160284;0.354513;,
  -0.920687;0.362445;0.144805;,
  -0.922506;0.357121;-0.146452;,
  -0.925592;0.147417;-0.348638;,
  -0.928149;-0.143820;-0.343300;,
  -0.928677;-0.345995;-0.133594;,
  -0.713235;-0.639947;0.285942;,
  -0.707509;-0.251525;0.660428;,
  -0.702764;0.287928;0.650554;,
  -0.701793;0.662407;0.262114;,
  -0.705152;0.652559;-0.277359;,
  -0.710874;0.264148;-0.651831;,
  -0.715624;-0.275304;-0.641943;,
  -0.716593;-0.649791;-0.253508;,
  -0.389823;-0.842795;0.371127;,
  -0.382338;-0.334192;0.861472;,
  -0.376126;0.372176;0.848537;,
  -0.374837;0.862528;0.339916;,
  -0.379235;0.849636;-0.366470;,
  -0.386726;0.341040;-0.856816;,
  -0.392927;-0.365334;-0.843884;,
  -0.394204;-0.855694;-0.335247;,
  -0.005731;-0.916706;0.399521;,
  0.002381;-0.365738;0.930715;,
  0.009097;0.399469;0.916701;,
  0.010483;0.930672;0.365704;,
  0.005734;0.916707;-0.399520;,
  -0.002376;0.365741;-0.930714;,
  -0.009098;-0.399475;-0.916699;,
  -0.010486;-0.930674;-0.365700;,
  0.379239;-0.849633;0.366471;,
  0.386737;-0.341033;0.856814;,
  0.392938;0.365322;0.843884;,
  0.394224;0.855682;0.335254;,
  0.389836;0.842786;-0.371133;,
  0.382338;0.334190;-0.861472;,
  0.376120;-0.372180;-0.848538;,
  0.374832;-0.862532;-0.339911;,
  0.705151;-0.652560;0.277358;,
  0.710871;-0.264143;0.651837;,
  0.715616;0.275294;0.641956;,
  0.716601;0.649779;0.253514;,
  0.713238;0.639939;-0.285952;,
  0.707514;0.251527;-0.660423;,
  0.702778;-0.287930;-0.650538;,
  0.701794;-0.662408;-0.262108;,
  0.922505;-0.357123;0.146449;,
  0.925586;-0.147420;0.348652;,
  0.928145;0.143816;0.343313;,
  0.928676;0.345997;0.133594;,
  0.926863;0.340691;-0.157652;,
  0.923781;0.130971;-0.359828;,
  0.921216;-0.160288;-0.354497;,
  0.920686;-0.362448;-0.144808;,
  -0.999942;0.008892;0.006050;,
  0.999942;-0.008899;-0.006054;,
  0.010356;-0.716374;-0.697640;,
  0.015906;0.007854;-0.999843;,
  0.011659;0.727239;-0.686286;,
  0.010356;-0.716374;-0.697640;,
  0.015908;0.007858;-0.999843;,
  0.011662;0.727241;-0.686283;,
  0.010356;-0.716374;-0.697640;,
  0.015909;0.007862;-0.999843;,
  0.011665;0.727244;-0.686280;,
  -0.999873;0.001028;-0.015892;,
  -0.999873;0.001036;-0.015897;,
  -0.999873;0.001044;-0.015902;,
  -0.999873;0.001019;-0.015905;,
  -0.999873;0.001030;-0.015901;,
  -0.999873;0.001040;-0.015897;,
  -0.011990;-0.705876;0.708234;,
  -0.015908;-0.007864;0.999843;,
  -0.010721;0.694664;0.719254;,
  -0.011992;-0.705878;0.708232;,
  -0.015910;-0.007867;0.999842;,
  -0.010721;0.694663;0.719255;,
  0.999873;-0.001033;0.015904;,
  0.999873;-0.001031;0.015903;,
  0.999873;-0.001028;0.015901;,
  0.000432;0.999290;0.037676;,
  -0.001380;-0.999758;0.021965;,
  -0.999873;0.001036;-0.015879;,
  -0.999873;0.001042;-0.015893;,
  -0.999873;0.001048;-0.015907;,
  -0.011987;-0.705874;0.708236;,
  -0.015905;-0.007861;0.999843;,
  -0.010720;0.694665;0.719253;,
  0.999873;-0.001038;0.015923;,
  0.999873;-0.001032;0.015917;,
  0.999873;-0.001027;0.015911;,
  0.999873;-0.001029;0.015885;,
  0.999873;-0.001029;0.015888;,
  0.999873;-0.001030;0.015891;,
  0.000431;0.999290;0.037679;,
  0.000433;0.999290;0.037673;,
  -0.001381;-0.999758;0.021967;,
  -0.001378;-0.999758;0.021964;;
  88;
  4;0,8,9,1;,
  4;1,9,10,2;,
  4;2,10,11,3;,
  4;3,11,12,4;,
  4;4,12,13,5;,
  4;5,13,14,6;,
  4;6,14,15,7;,
  4;7,15,8,0;,
  4;8,16,17,9;,
  4;9,17,18,10;,
  4;10,18,19,11;,
  4;11,19,20,12;,
  4;12,20,21,13;,
  4;13,21,22,14;,
  4;14,22,23,15;,
  4;15,23,16,8;,
  4;16,24,25,17;,
  4;17,25,26,18;,
  4;18,26,27,19;,
  4;19,27,28,20;,
  4;20,28,29,21;,
  4;21,29,30,22;,
  4;22,30,31,23;,
  4;23,31,24,16;,
  4;24,32,33,25;,
  4;25,33,34,26;,
  4;26,34,35,27;,
  4;27,35,36,28;,
  4;28,36,37,29;,
  4;29,37,38,30;,
  4;30,38,39,31;,
  4;31,39,32,24;,
  4;32,40,41,33;,
  4;33,41,42,34;,
  4;34,42,43,35;,
  4;35,43,44,36;,
  4;36,44,45,37;,
  4;37,45,46,38;,
  4;38,46,47,39;,
  4;39,47,40,32;,
  4;40,48,49,41;,
  4;41,49,50,42;,
  4;42,50,51,43;,
  4;43,51,52,44;,
  4;44,52,53,45;,
  4;45,53,54,46;,
  4;46,54,55,47;,
  4;47,55,48,40;,
  3;1,56,0;,
  3;2,56,1;,
  3;3,56,2;,
  3;4,56,3;,
  3;5,56,4;,
  3;6,56,5;,
  3;7,56,6;,
  3;0,56,7;,
  3;48,57,49;,
  3;49,57,50;,
  3;50,57,51;,
  3;51,57,52;,
  3;52,57,53;,
  3;53,57,54;,
  3;54,57,55;,
  3;55,57,48;,
  4;58,61,62,59;,
  4;59,62,63,60;,
  4;61,64,65,62;,
  4;62,65,66,63;,
  4;84,67,68,85;,
  4;85,68,69,86;,
  4;67,70,71,68;,
  4;68,71,72,69;,
  4;87,73,74,88;,
  4;88,74,75,89;,
  4;73,76,77,74;,
  4;74,77,78,75;,
  4;90,79,80,91;,
  4;91,80,81,92;,
  4;79,93,94,80;,
  4;80,94,95,81;,
  4;96,82,75,78;,
  4;60,63,82,96;,
  4;82,97,89,75;,
  4;63,66,97,82;,
  4;76,73,83,98;,
  4;98,83,61,58;,
  4;73,87,99,83;,
  4;83,99,64,61;;
 }
 MeshTextureCoords {
  84;
  0.669050;0.149680;,
  0.655580;0.157920;,
  0.641540;0.149580;,
  0.661450;0.145170;,
  0.653900;0.140630;,
  0.668140;0.140320;,
  0.685440;0.136310;,
  0.685200;0.137990;,
  0.717670;0.139150;,
  0.702650;0.139520;,
  0.731710;0.147490;,
  0.710250;0.144040;,
  0.719340;0.156440;,
  0.703550;0.148880;,
  0.687810;0.160760;,
  0.686490;0.151220;,
  0.647230;0.166680;,
  0.628880;0.155790;,
  0.645040;0.144090;,
  0.686240;0.138450;,
  0.728340;0.142170;,
  0.746690;0.153060;,
  0.730540;0.164750;,
  0.689340;0.170400;,
  0.645260;0.174640;,
  0.625400;0.162840;,
  0.642890;0.150190;,
  0.687480;0.144080;,
  0.733060;0.148100;,
  0.752920;0.159900;,
  0.735430;0.172550;,
  0.690830;0.178660;,
  0.649970;0.180570;,
  0.631620;0.169680;,
  0.647780;0.157980;,
  0.688980;0.152340;,
  0.731090;0.156060;,
  0.749440;0.166950;,
  0.733280;0.178650;,
  0.692080;0.184290;,
  0.660650;0.183580;,
  0.646610;0.175250;,
  0.658970;0.166300;,
  0.690510;0.161980;,
  0.722730;0.164820;,
  0.736780;0.173160;,
  0.724410;0.182110;,
  0.692880;0.186430;,
  0.675670;0.183220;,
  0.668070;0.178700;,
  0.674760;0.173860;,
  0.691830;0.171520;,
  0.709270;0.173060;,
  0.716870;0.177570;,
  0.710180;0.182420;,
  0.693110;0.184750;,
  0.685570;0.143220;,
  0.692740;0.179520;,
  0.221240;0.755710;,
  0.215080;0.709970;,
  0.235300;0.702740;,
  0.241460;0.748480;,
  0.237360;0.693800;,
  0.243520;0.739530;,
  0.208320;0.659750;,
  0.228530;0.652520;,
  0.230600;0.643570;,
  0.170950;0.659070;,
  0.185550;0.648470;,
  0.200150;0.637870;,
  0.147160;0.653990;,
  0.149280;0.645050;,
  0.169440;0.637810;,
  0.153920;0.704210;,
  0.156040;0.695270;,
  0.176200;0.688030;,
  0.160080;0.749950;,
  0.162200;0.741010;,
  0.182370;0.733770;,
  0.183880;0.755030;,
  0.198480;0.744430;,
  0.213080;0.733830;,
  0.206920;0.688090;,
  0.177720;0.709290;;
 }
}
