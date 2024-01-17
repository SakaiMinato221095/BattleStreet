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
 114;
 -21.29530;-21.43550;-10.45280;,
 -21.25450;-10.74850;-10.45690;,
 -13.07510;-10.72170;-14.33950;,
 -13.11580;-21.40870;-14.33540;,
 0.12240;-10.68070;-14.83420;,
 0.08160;-21.36780;-14.83010;,
 13.31130;-10.64010;-14.55300;,
 13.27060;-21.32710;-14.54890;,
 21.40680;-10.61660;-10.80200;,
 21.36600;-21.30360;-10.79800;,
 -22.80970;2.15720;-10.44890;,
 -13.03420;-0.03460;-14.34370;,
 0.16320;0.00630;-14.83830;,
 13.35210;0.04690;-14.55710;,
 23.06070;2.29900;-10.82000;,
 -26.22860;10.61000;-10.42420;,
 -12.99340;10.65240;-14.34780;,
 0.20400;10.69330;-14.84240;,
 13.39290;10.73400;-14.56130;,
 26.54420;10.77320;-10.85120;,
 -26.18780;21.29700;-10.42840;,
 -12.95270;21.33940;-14.35190;,
 0.24480;21.38040;-14.84650;,
 13.43370;21.42110;-14.56540;,
 26.58490;21.46020;-10.85530;,
 -28.08130;21.28900;-4.78400;,
 -13.04560;24.20710;-4.90670;,
 0.14760;24.24790;-5.01340;,
 13.34080;24.28870;-5.12020;,
 28.35450;21.46350;-5.24070;,
 -28.13630;21.28690;0.22010;,
 -13.10060;24.20500;0.09740;,
 0.09260;26.06100;-0.00930;,
 13.28580;24.28660;-0.11610;,
 28.29950;21.46140;-0.23650;,
 -28.13630;21.28690;0.22010;,
 -28.19970;21.28440;5.98190;,
 -13.16400;24.20250;5.85920;,
 -13.10060;24.20500;0.09740;,
 0.02920;24.24330;5.75250;,
 0.09260;26.06100;-0.00930;,
 13.22240;24.28410;5.64570;,
 13.28580;24.28660;-0.11610;,
 28.23610;21.45890;5.52530;,
 28.29950;21.46140;-0.23650;,
 -26.42620;21.28780;11.24310;,
 -13.24680;21.32810;12.38960;,
 -0.06000;21.36870;12.86590;,
 13.13960;21.40970;12.17610;,
 26.34660;21.45100;10.81610;,
 -26.46700;10.60080;11.24720;,
 -13.28760;10.64110;12.39380;,
 -0.10080;10.68160;12.87000;,
 13.09880;10.72270;12.18030;,
 26.30580;10.76400;10.82030;,
 -23.04810;2.14800;11.22250;,
 -13.32840;-0.04600;12.39790;,
 -0.14160;-0.00540;12.87410;,
 13.05800;0.03560;12.18440;,
 22.82230;2.28980;10.85140;,
 -21.49290;-10.75770;11.21450;,
 -13.36920;-10.73300;12.40200;,
 -0.18240;-10.69250;12.87820;,
 13.01720;-10.65140;12.18850;,
 21.16850;-10.62580;10.86940;,
 -21.53370;-21.44470;11.21870;,
 -13.41000;-21.42010;12.40610;,
 -0.22320;-21.37950;12.88230;,
 12.97640;-21.33850;12.19260;,
 21.12760;-21.31280;10.87350;,
 -23.30720;-21.44810;5.95750;,
 -13.33820;-26.79270;5.87680;,
 -0.14790;-26.75200;6.03640;,
 13.04820;-26.71110;5.66330;,
 23.01720;-21.30490;5.58260;,
 -23.24380;-21.44570;0.19560;,
 -13.27480;-26.79030;0.11500;,
 -0.08160;-30.75110;0.00820;,
 13.11160;-26.70870;-0.09850;,
 23.08060;-21.30240;-0.17920;,
 -23.24380;-21.44570;0.19560;,
 -23.18870;-21.44360;-4.80850;,
 -13.21970;-26.78820;-4.88910;,
 -13.27480;-26.79030;0.11500;,
 -0.02660;-26.74730;-4.99590;,
 -0.08160;-30.75110;0.00820;,
 13.16660;-26.70660;-5.10260;,
 13.11160;-26.70870;-0.09850;,
 23.13560;-21.30030;-5.18330;,
 23.08060;-21.30240;-0.17920;,
 23.05800;-10.61780;5.57850;,
 23.12140;-10.61540;-0.18330;,
 23.17640;-10.61330;-5.18740;,
 23.12140;-10.61540;-0.18330;,
 24.71180;2.29770;5.56060;,
 24.77520;2.30020;-0.20130;,
 24.83020;2.30230;-5.20530;,
 24.77520;2.30020;-0.20130;,
 28.19530;10.77190;5.52940;,
 28.25870;10.77430;-0.23240;,
 28.31370;10.77650;-5.23650;,
 28.25870;10.77430;-0.23240;,
 -23.26640;-10.76110;5.95330;,
 -23.20300;-10.75860;0.19150;,
 -23.20300;-10.75860;0.19150;,
 -23.14790;-10.75650;-4.81260;,
 -24.82160;2.14460;5.96130;,
 -24.75820;2.14700;0.19950;,
 -24.75820;2.14700;0.19950;,
 -24.70320;2.14910;-4.80460;,
 -28.24040;10.59740;5.98600;,
 -28.17710;10.59980;0.22420;,
 -28.17710;10.59980;0.22420;,
 -28.12200;10.60190;-4.77990;;
 
 96;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;5,4,6,7;,
 4;7,6,8,9;,
 4;1,10,11,2;,
 4;2,11,12,4;,
 4;4,12,13,6;,
 4;6,13,14,8;,
 4;10,15,16,11;,
 4;11,16,17,12;,
 4;12,17,18,13;,
 4;13,18,19,14;,
 4;15,20,21,16;,
 4;16,21,22,17;,
 4;17,22,23,18;,
 4;18,23,24,19;,
 4;20,25,26,21;,
 4;21,26,27,22;,
 4;22,27,28,23;,
 4;23,28,29,24;,
 4;25,30,31,26;,
 4;26,31,32,27;,
 4;27,32,33,28;,
 4;28,33,34,29;,
 4;35,36,37,38;,
 4;38,37,39,40;,
 4;40,39,41,42;,
 4;42,41,43,44;,
 4;36,45,46,37;,
 4;37,46,47,39;,
 4;39,47,48,41;,
 4;41,48,49,43;,
 4;45,50,51,46;,
 4;46,51,52,47;,
 4;47,52,53,48;,
 4;48,53,54,49;,
 4;50,55,56,51;,
 4;51,56,57,52;,
 4;52,57,58,53;,
 4;53,58,59,54;,
 4;55,60,61,56;,
 4;56,61,62,57;,
 4;57,62,63,58;,
 4;58,63,64,59;,
 4;60,65,66,61;,
 4;61,66,67,62;,
 4;62,67,68,63;,
 4;63,68,69,64;,
 4;65,70,71,66;,
 4;66,71,72,67;,
 4;67,72,73,68;,
 4;68,73,74,69;,
 4;70,75,76,71;,
 4;71,76,77,72;,
 4;72,77,78,73;,
 4;73,78,79,74;,
 4;80,81,82,83;,
 4;83,82,84,85;,
 4;85,84,86,87;,
 4;87,86,88,89;,
 4;81,0,3,82;,
 4;82,3,5,84;,
 4;84,5,7,86;,
 4;86,7,9,88;,
 4;74,90,64,69;,
 4;79,91,90,74;,
 4;88,92,93,89;,
 4;9,8,92,88;,
 4;90,94,59,64;,
 4;91,95,94,90;,
 4;92,96,97,93;,
 4;8,14,96,92;,
 4;94,98,54,59;,
 4;95,99,98,94;,
 4;96,100,101,97;,
 4;14,19,100,96;,
 4;98,43,49,54;,
 4;99,44,43,98;,
 4;100,29,34,101;,
 4;19,24,29,100;,
 4;65,60,102,70;,
 4;70,102,103,75;,
 4;80,104,105,81;,
 4;81,105,1,0;,
 4;60,55,106,102;,
 4;102,106,107,103;,
 4;104,108,109,105;,
 4;105,109,10,1;,
 4;55,50,110,106;,
 4;106,110,111,107;,
 4;108,112,113,109;,
 4;109,113,15,10;,
 4;50,45,36,110;,
 4;110,36,35,111;,
 4;112,30,25,113;,
 4;113,25,20,15;;
 
 MeshMaterialList {
  1;
  96;
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
    "data\\Texture\\UV_PlayerHero.png";
   }
  }
 }
 MeshNormals {
  137;
  -0.748078;0.002600;-0.663606;,
  -0.238021;0.000535;-0.971260;,
  -0.008073;-0.000353;-0.999967;,
  0.225648;-0.001232;-0.974208;,
  0.751070;-0.003117;-0.660215;,
  -0.742599;-0.035570;-0.668791;,
  -0.231360;-0.005374;-0.972853;,
  -0.008073;-0.000354;-0.999967;,
  0.218805;-0.007172;-0.975742;,
  0.745282;-0.041875;-0.665433;,
  -0.710773;-0.152185;-0.686762;,
  -0.204456;-0.019706;-0.978677;,
  -0.008072;-0.000355;-0.999967;,
  0.191194;-0.021444;-0.981318;,
  0.712065;-0.159800;-0.683686;,
  -0.691931;-0.115572;-0.712654;,
  -0.173189;-0.013898;-0.984791;,
  -0.008073;-0.000354;-0.999967;,
  0.159041;-0.015310;-0.987153;,
  0.693014;-0.122524;-0.710436;,
  -0.694456;0.002369;-0.719531;,
  -0.162110;0.000237;-0.986773;,
  -0.008073;-0.000353;-0.999967;,
  0.147599;-0.000942;-0.989047;,
  0.696294;-0.002931;-0.717751;,
  -0.166451;0.981924;-0.090103;,
  -0.104453;0.981431;-0.160881;,
  -0.005828;0.973282;-0.229540;,
  0.095082;0.982766;-0.158529;,
  0.159405;0.983395;-0.086744;,
  -0.190536;0.981679;-0.001676;,
  -0.131765;0.991258;-0.006686;,
  -0.003385;0.999941;-0.010369;,
  0.125591;0.992077;-0.003217;,
  0.184948;0.982745;0.002453;,
  -0.154380;0.980869;0.118590;,
  -0.096746;0.975787;0.196164;,
  0.000030;0.962062;0.272830;,
  0.094829;0.975502;0.198503;,
  0.150546;0.981060;0.121888;,
  -0.115789;0.964590;0.236980;,
  -0.062167;0.947291;0.314285;,
  0.000297;0.921315;0.388816;,
  0.061466;0.946915;0.315555;,
  0.113818;0.964219;0.239431;,
  -0.094951;-0.008909;0.995442;,
  -0.065549;-0.004194;0.997840;,
  0.008053;0.000355;0.999968;,
  0.081470;-0.004737;0.996665;,
  0.110688;-0.009657;0.993808;,
  -0.118662;-0.012910;0.992851;,
  -0.077442;-0.006199;0.996978;,
  0.008053;0.000353;0.999967;,
  0.093251;-0.006824;0.995619;,
  0.134165;-0.013820;0.990863;,
  -0.139360;-0.003173;0.990237;,
  -0.087843;-0.001328;0.996133;,
  0.008053;0.000353;0.999967;,
  0.103509;-0.002050;0.994627;,
  0.154564;-0.004278;0.987974;,
  -0.144637;0.000936;0.989484;,
  -0.070674;-0.284447;0.956083;,
  0.008609;-0.432155;0.901758;,
  0.155259;-0.469052;0.869417;,
  0.159750;-0.000232;0.987157;,
  -0.392663;-0.895328;0.210245;,
  -0.235685;-0.908761;0.344392;,
  0.006322;-0.885435;0.464720;,
  0.245467;-0.904764;0.348064;,
  0.399557;-0.890514;0.217574;,
  -0.472528;-0.881298;-0.005570;,
  -0.310120;-0.950589;-0.014376;,
  0.002826;-0.999742;-0.022518;,
  0.315076;-0.949032;-0.008134;,
  0.476744;-0.879029;0.004872;,
  -0.419788;-0.891714;-0.169186;,
  -0.247634;-0.922442;-0.296273;,
  -0.000340;-0.912555;-0.408955;,
  0.248878;-0.923577;-0.291660;,
  0.422547;-0.892015;-0.160509;,
  0.982336;-0.064381;0.175702;,
  0.997791;-0.065525;0.010945;,
  0.987098;-0.064973;-0.146345;,
  0.952605;-0.251902;0.170556;,
  0.966680;-0.255772;0.010522;,
  0.956788;-0.253719;-0.142070;,
  0.965881;-0.192776;0.172947;,
  0.980622;-0.195618;0.010701;,
  0.970333;-0.194170;-0.144056;,
  -0.986061;-0.057337;0.156194;,
  -0.998255;-0.058018;-0.011010;,
  -0.984405;-0.057207;-0.166358;,
  -0.957032;-0.247019;0.151891;,
  -0.968329;-0.249445;-0.010756;,
  -0.955613;-0.246126;-0.161941;,
  -0.970153;-0.187366;0.153937;,
  -0.981898;-0.189100;-0.010878;,
  -0.968620;-0.186708;-0.164059;,
  -0.140968;0.973923;-0.177768;,
  -0.075456;0.969692;-0.232389;,
  -0.005196;0.958429;-0.285283;,
  0.065996;0.970691;-0.231091;,
  0.132490;0.975580;-0.175187;,
  -0.086670;0.000718;0.996237;,
  -0.061402;0.000622;0.998113;,
  0.008053;0.000358;0.999967;,
  0.077333;0.000094;0.997005;,
  0.102434;-0.000000;0.994740;,
  -0.291928;-0.861772;0.414882;,
  0.301862;-0.856287;0.419108;,
  -0.354598;-0.875682;-0.327781;,
  -0.184837;-0.890737;-0.415238;,
  -0.001133;-0.873170;-0.487414;,
  0.184236;-0.892382;-0.411961;,
  0.355479;-0.877834;-0.321000;,
  0.984369;-0.003693;0.176082;,
  0.939994;-0.061474;0.335607;,
  0.941741;-0.003471;0.336321;,
  0.999932;-0.003813;0.010995;,
  0.989184;-0.003832;-0.146633;,
  0.913977;-0.241540;0.326044;,
  0.925607;-0.184838;0.330282;,
  0.984369;-0.003690;0.176079;,
  0.941743;-0.003465;0.336316;,
  0.999932;-0.003813;0.010995;,
  0.989184;-0.003831;-0.146629;,
  -0.947604;0.003743;0.319426;,
  -0.946162;-0.055047;0.318978;,
  -0.987684;0.003832;0.156416;,
  -0.999932;0.003813;-0.011005;,
  -0.986026;0.003700;-0.166550;,
  -0.920327;-0.238035;0.310383;,
  -0.932007;-0.180533;0.314278;,
  -0.947607;0.003736;0.319418;,
  -0.987684;0.003826;0.156416;,
  -0.999932;0.003809;-0.010996;,
  -0.986026;0.003695;-0.166548;;
  96;
  4;0,5,6,1;,
  4;1,6,7,2;,
  4;2,7,8,3;,
  4;3,8,9,4;,
  4;5,10,11,6;,
  4;6,11,12,7;,
  4;7,12,13,8;,
  4;8,13,14,9;,
  4;10,15,16,11;,
  4;11,16,17,12;,
  4;12,17,18,13;,
  4;13,18,19,14;,
  4;15,20,21,16;,
  4;16,21,22,17;,
  4;17,22,23,18;,
  4;18,23,24,19;,
  4;98,25,26,99;,
  4;99,26,27,100;,
  4;100,27,28,101;,
  4;101,28,29,102;,
  4;25,30,31,26;,
  4;26,31,32,27;,
  4;27,32,33,28;,
  4;28,33,34,29;,
  4;30,35,36,31;,
  4;31,36,37,32;,
  4;32,37,38,33;,
  4;33,38,39,34;,
  4;35,40,41,36;,
  4;36,41,42,37;,
  4;37,42,43,38;,
  4;38,43,44,39;,
  4;103,45,46,104;,
  4;104,46,47,105;,
  4;105,47,48,106;,
  4;106,48,49,107;,
  4;45,50,51,46;,
  4;46,51,52,47;,
  4;47,52,53,48;,
  4;48,53,54,49;,
  4;50,55,56,51;,
  4;51,56,57,52;,
  4;52,57,58,53;,
  4;53,58,59,54;,
  4;55,60,61,56;,
  4;56,61,62,57;,
  4;57,62,63,58;,
  4;58,63,64,59;,
  4;108,65,66,108;,
  4;61,66,67,62;,
  4;62,67,68,63;,
  4;63,68,69,109;,
  4;65,70,71,66;,
  4;66,71,72,67;,
  4;67,72,73,68;,
  4;68,73,74,69;,
  4;70,75,76,71;,
  4;71,76,77,72;,
  4;72,77,78,73;,
  4;73,78,79,74;,
  4;75,110,111,76;,
  4;76,111,112,77;,
  4;77,112,113,78;,
  4;78,113,114,79;,
  4;115,80,116,117;,
  4;118,81,80,115;,
  4;119,82,81,118;,
  4;4,9,82,119;,
  4;80,83,120,116;,
  4;81,84,83,80;,
  4;82,85,84,81;,
  4;9,14,85,82;,
  4;83,86,121,120;,
  4;84,87,86,83;,
  4;85,88,87,84;,
  4;14,19,88,85;,
  4;86,122,123,121;,
  4;87,124,122,86;,
  4;88,125,124,87;,
  4;19,24,125,88;,
  4;126,127,89,128;,
  4;128,89,90,129;,
  4;129,90,91,130;,
  4;130,91,5,0;,
  4;127,131,92,89;,
  4;89,92,93,90;,
  4;90,93,94,91;,
  4;91,94,10,5;,
  4;131,132,95,92;,
  4;92,95,96,93;,
  4;93,96,97,94;,
  4;94,97,15,10;,
  4;132,133,134,95;,
  4;95,134,135,96;,
  4;96,135,136,97;,
  4;97,136,20,15;;
 }
 MeshTextureCoords {
  114;
  0.566330;0.574840;,
  0.566670;0.484040;,
  0.635800;0.483810;,
  0.635460;0.574620;,
  0.747340;0.483460;,
  0.747000;0.574270;,
  0.858810;0.483120;,
  0.858470;0.573920;,
  0.927230;0.482920;,
  0.926890;0.573720;,
  0.553530;0.374380;,
  0.636150;0.393010;,
  0.747690;0.392660;,
  0.859160;0.392310;,
  0.941210;0.373180;,
  0.524630;0.302560;,
  0.636490;0.302200;,
  0.748030;0.301850;,
  0.859500;0.301510;,
  0.970650;0.301170;,
  0.524980;0.211750;,
  0.636840;0.211390;,
  0.748380;0.211050;,
  0.859850;0.210700;,
  0.971000;0.210370;,
  0.508970;0.211820;,
  0.636050;0.187030;,
  0.747560;0.186680;,
  0.859060;0.186330;,
  0.985950;0.210340;,
  0.508510;0.214550;,
  0.635590;0.189760;,
  0.747090;0.189410;,
  0.858600;0.189060;,
  0.985490;0.213070;,
  0.286420;0.297640;,
  0.286200;0.297650;,
  0.338580;0.287430;,
  0.338800;0.287420;,
  0.384550;0.287290;,
  0.384770;0.287280;,
  0.430510;0.287150;,
  0.430730;0.287140;,
  0.482820;0.297040;,
  0.483040;0.297030;,
  0.292380;0.297640;,
  0.338290;0.297500;,
  0.384230;0.297360;,
  0.430220;0.297210;,
  0.476230;0.297070;,
  0.292230;0.335070;,
  0.338150;0.334930;,
  0.384090;0.334790;,
  0.430080;0.334650;,
  0.476090;0.334500;,
  0.304150;0.364680;,
  0.338010;0.372360;,
  0.383950;0.372220;,
  0.429940;0.372080;,
  0.463960;0.364180;,
  0.309560;0.409880;,
  0.337870;0.409800;,
  0.383810;0.409650;,
  0.429790;0.409510;,
  0.458190;0.409420;,
  0.309420;0.447310;,
  0.337730;0.447230;,
  0.383670;0.447090;,
  0.429650;0.446940;,
  0.458050;0.446850;,
  0.303240;0.447330;,
  0.337970;0.447220;,
  0.383930;0.447080;,
  0.429900;0.446930;,
  0.464640;0.446820;,
  0.303460;0.447320;,
  0.338200;0.447210;,
  0.384160;0.447070;,
  0.430120;0.446920;,
  0.464860;0.446820;,
  0.549860;0.577640;,
  0.550320;0.574910;,
  0.634580;0.574650;,
  0.634110;0.577380;,
  0.746080;0.574300;,
  0.745620;0.577030;,
  0.857590;0.573960;,
  0.857120;0.576690;,
  0.941840;0.573700;,
  0.941380;0.576420;,
  0.464780;0.409390;,
  0.465000;0.409380;,
  0.942190;0.482890;,
  0.941720;0.485620;,
  0.470540;0.364150;,
  0.470760;0.364150;,
  0.956170;0.373150;,
  0.955700;0.375880;,
  0.482670;0.334470;,
  0.482900;0.334470;,
  0.985610;0.301150;,
  0.985140;0.303870;,
  0.303380;0.409890;,
  0.303610;0.409890;,
  0.550200;0.486840;,
  0.550670;0.484110;,
  0.297970;0.364690;,
  0.298190;0.364680;,
  0.537060;0.377180;,
  0.537520;0.374450;,
  0.286060;0.335080;,
  0.286280;0.335080;,
  0.508160;0.305360;,
  0.508630;0.302630;;
 }
}