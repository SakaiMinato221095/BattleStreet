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
 98;
 5.93047;-25.52238;-11.23017;,
 3.26865;-25.49827;-14.72643;,
 3.32745;-24.23256;-14.71778;,
 5.98931;-24.25665;-11.22153;,
 0.00000;-25.47653;-16.19909;,
 0.00000;-24.21079;-16.19044;,
 -3.26865;-25.49827;-14.72643;,
 -3.32745;-24.23256;-14.71778;,
 -5.93047;-25.52238;-11.23017;,
 -5.98931;-24.25665;-11.22153;,
 3.37666;-22.37914;-14.71057;,
 6.03848;-22.40326;-11.21428;,
 0.00000;-22.35740;-16.18320;,
 -3.37666;-22.37914;-14.71057;,
 -6.03848;-22.40326;-11.21428;,
 3.42597;-20.53317;-14.70329;,
 6.08779;-20.55729;-11.20704;,
 0.00000;-20.51140;-16.17595;,
 -3.42597;-20.53317;-14.70329;,
 -6.08779;-20.55729;-11.20704;,
 3.50315;-18.64418;-11.66809;,
 5.69531;-18.93532;-9.53551;,
 0.00000;-17.93141;-13.19581;,
 -3.50315;-18.64418;-11.66809;,
 -5.69531;-18.93532;-9.53551;,
 3.29340;-17.12218;-6.28197;,
 5.99536;-17.14902;-4.09951;,
 0.00000;-17.09911;-6.33056;,
 -3.29340;-17.12218;-6.28197;,
 -5.99536;-17.14902;-4.09951;,
 2.63728;0.24321;-4.74484;,
 5.00591;0.42577;-4.12783;,
 0.08551;0.29407;-4.95072;,
 -2.64436;0.22614;-4.83658;,
 -4.90703;0.16562;-4.16692;,
 2.64208;0.05012;-0.14721;,
 6.33413;0.39788;0.25456;,
 0.00000;0.08785;-0.21802;,
 -2.64208;0.05012;-0.14721;,
 -6.28488;0.15071;0.21542;,
 2.66147;0.38371;4.25358;,
 4.60341;0.32627;4.17284;,
 0.02352;0.25028;4.68748;,
 -2.57950;0.27244;4.25859;,
 -4.63474;0.06289;4.13378;,
 3.20614;-20.48669;5.46493;,
 5.51170;-20.53310;3.85427;,
 -0.00000;-20.45932;5.92557;,
 -3.20614;-20.48669;5.46493;,
 -5.51170;-20.53310;3.85427;,
 3.25570;-22.31782;5.45765;,
 5.56125;-22.36423;3.84699;,
 -0.00000;-22.29045;5.91829;,
 -3.25570;-22.31782;5.45765;,
 -5.56125;-22.36423;3.84699;,
 3.30442;-24.20103;5.45048;,
 5.60997;-24.24744;3.83985;,
 -0.00000;-24.17366;5.91112;,
 -3.30442;-24.20103;5.45048;,
 -5.60997;-24.24744;3.83985;,
 3.24607;-25.49614;5.44191;,
 5.50512;-25.54268;3.78651;,
 -0.00000;-25.46877;5.90254;,
 -3.24607;-25.49614;5.44191;,
 -5.50512;-25.54268;3.78651;,
 3.26865;-25.49827;-0.15466;,
 6.55820;-25.54090;-0.07476;,
 0.00000;-25.47237;-0.20325;,
 -3.26865;-25.49827;-0.15466;,
 -6.55820;-25.54090;-0.07476;,
 3.26865;-25.49827;-5.01193;,
 6.68192;-25.53715;-2.53239;,
 0.00000;-25.47237;-5.06051;,
 -3.26865;-25.49827;-5.01193;,
 -6.68192;-25.53715;-2.53239;,
 3.26865;-25.49827;-9.86919;,
 6.45341;-25.53093;-6.35691;,
 0.00000;-25.47237;-9.91778;,
 -3.26865;-25.49827;-9.86919;,
 -6.45341;-25.53093;-6.35691;,
 -6.61654;-24.24579;-0.06615;,
 -6.74026;-24.24205;-2.52381;,
 -6.51221;-24.26518;-6.34827;,
 -6.56782;-22.36259;-0.05901;,
 -6.69155;-22.35884;-2.51667;,
 -6.56142;-22.41179;-6.34102;,
 -6.51826;-20.53145;-0.05173;,
 -6.64198;-20.52771;-2.50936;,
 -6.61073;-20.56579;-6.33378;,
 6.61654;-24.24579;-0.06615;,
 6.74026;-24.24205;-2.52381;,
 6.51221;-24.26518;-6.34827;,
 6.56782;-22.36259;-0.05901;,
 6.69155;-22.35884;-2.51667;,
 6.56142;-22.41179;-6.34102;,
 6.51826;-20.53145;-0.05173;,
 6.64198;-20.52771;-2.50936;,
 6.61073;-20.56579;-6.33378;;
 
 96;
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
 4;31,30,35,36;,
 4;30,32,37,35;,
 4;32,33,38,37;,
 4;33,34,39,38;,
 4;36,35,40,41;,
 4;35,37,42,40;,
 4;37,38,43,42;,
 4;38,39,44,43;,
 4;41,40,45,46;,
 4;40,42,47,45;,
 4;42,43,48,47;,
 4;43,44,49,48;,
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
 4;76,75,1,0;,
 4;75,77,4,1;,
 4;77,78,6,4;,
 4;78,79,8,6;,
 4;69,64,59,80;,
 4;74,69,80,81;,
 4;79,74,81,82;,
 4;8,79,82,9;,
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
 4;61,66,89,56;,
 4;66,71,90,89;,
 4;71,76,91,90;,
 4;76,0,3,91;,
 4;56,89,92,51;,
 4;89,90,93,92;,
 4;90,91,94,93;,
 4;91,3,11,94;,
 4;51,92,95,46;,
 4;92,93,96,95;,
 4;93,94,97,96;,
 4;94,11,16,97;,
 4;46,95,36,41;,
 4;95,96,31,36;,
 4;96,97,26,31;,
 4;97,16,21,26;;
 
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
  128;
  0.928267;-0.040611;-0.369691;,
  0.620772;-0.018566;-0.783771;,
  0.000000;-0.003463;-0.999994;,
  -0.620772;-0.018566;-0.783771;,
  -0.928267;-0.040611;-0.369691;,
  0.928579;-0.031912;-0.369760;,
  0.619667;-0.014575;-0.784730;,
  0.000000;-0.002679;-0.999996;,
  -0.619667;-0.014575;-0.784730;,
  -0.928579;-0.031912;-0.369760;,
  0.928819;-0.023284;-0.369801;,
  0.617500;-0.010596;-0.786500;,
  0.000000;-0.001855;-0.999998;,
  -0.617500;-0.010596;-0.786500;,
  -0.928819;-0.023284;-0.369801;,
  0.901262;0.250011;-0.353865;,
  0.583626;0.390887;-0.711750;,
  0.000000;0.454195;-0.890902;,
  -0.583626;0.390887;-0.711750;,
  -0.901262;0.250011;-0.353865;,
  0.664226;0.678381;-0.314012;,
  0.346832;0.853291;-0.389361;,
  0.000000;0.915290;-0.402796;,
  -0.346832;0.853291;-0.389361;,
  -0.664226;0.678381;-0.314012;,
  0.703368;0.675019;-0.222761;,
  0.220874;0.945700;-0.238465;,
  0.000000;0.980258;-0.197720;,
  -0.220874;0.945700;-0.238465;,
  -0.703368;0.675019;-0.222761;,
  0.899708;0.075780;-0.429863;,
  0.254394;0.070157;-0.964553;,
  0.009555;0.082582;-0.996539;,
  -0.253981;0.074910;-0.964304;,
  -0.901781;0.081717;-0.424398;,
  -0.062684;0.998021;-0.005067;,
  -0.032622;0.999453;-0.005383;,
  -0.006016;0.999977;-0.003188;,
  -0.011839;0.999929;0.001096;,
  -0.014181;0.999895;0.002873;,
  -0.032582;0.998266;-0.049019;,
  -0.026200;0.998322;-0.051640;,
  -0.010318;0.998796;-0.047967;,
  -0.017893;0.999376;-0.030469;,
  -0.034961;0.999203;-0.019255;,
  0.767290;0.025696;0.640785;,
  0.301860;0.027382;0.952959;,
  -0.000358;0.029441;0.999566;,
  -0.305045;0.027646;0.951936;,
  -0.770434;0.026312;0.636977;,
  0.821457;0.019527;0.569936;,
  0.366512;0.005121;0.930399;,
  0.000000;-0.002034;0.999998;,
  -0.366512;0.005121;0.930399;,
  -0.821457;0.019527;0.569936;,
  0.821827;-0.023133;0.569267;,
  0.368309;-0.014369;0.929592;,
  0.000000;-0.005883;0.999983;,
  -0.368309;-0.014369;0.929592;,
  -0.821827;-0.023133;0.569267;,
  0.820732;-0.065170;0.567584;,
  0.370458;-0.033756;0.928236;,
  0.000000;-0.009759;0.999952;,
  -0.370458;-0.033756;0.928236;,
  -0.820732;-0.065170;0.567584;,
  -0.014385;-0.999895;-0.001461;,
  -0.011208;-0.999937;-0.000613;,
  0.000000;-1.000000;0.000235;,
  0.011208;-0.999937;-0.000613;,
  0.014385;-0.999895;-0.001461;,
  -0.011305;-0.999936;-0.000791;,
  -0.009614;-0.999954;-0.000396;,
  0.000000;-1.000000;-0.000000;,
  0.009614;-0.999954;-0.000396;,
  0.011305;-0.999936;-0.000791;,
  -0.009855;-0.999951;-0.000433;,
  -0.008768;-0.999962;-0.000133;,
  0.000000;-1.000000;0.000166;,
  0.008768;-0.999962;-0.000133;,
  0.009855;-0.999951;-0.000433;,
  -0.988202;-0.015672;0.152354;,
  -0.999866;-0.016282;-0.001462;,
  -0.996370;-0.029206;-0.079958;,
  -0.988255;0.025572;0.150656;,
  -0.999880;0.013159;0.008181;,
  -0.997435;-0.013004;-0.070385;,
  -0.991754;0.027098;0.125256;,
  -0.997177;0.046090;-0.059271;,
  -0.990264;0.099358;-0.097493;,
  0.988202;-0.015672;0.152354;,
  0.999866;-0.016282;-0.001462;,
  0.996370;-0.029206;-0.079958;,
  0.988255;0.025572;0.150656;,
  0.999880;0.013159;0.008181;,
  0.997435;-0.013004;-0.070385;,
  0.991352;0.025899;0.128649;,
  0.997236;0.044578;-0.059448;,
  0.990188;0.098642;-0.098979;,
  0.806055;0.097704;-0.583720;,
  -0.812610;0.105087;-0.573255;,
  -0.092607;0.994943;0.038900;,
  -0.038981;0.998400;0.040951;,
  -0.001701;0.999133;0.041602;,
  -0.005774;0.999450;0.032657;,
  0.006612;0.999666;0.024998;,
  0.704210;0.031458;0.709294;,
  0.236721;0.048859;0.970348;,
  -0.000716;0.060963;0.998140;,
  -0.243100;0.049401;0.968742;,
  -0.711354;0.032730;0.702072;,
  -0.016622;-0.999860;-0.001835;,
  -0.012380;-0.999923;-0.000683;,
  0.000000;-1.000000;0.000470;,
  0.012380;-0.999923;-0.000683;,
  0.016622;-0.999860;-0.001835;,
  -0.008342;-0.999965;-0.000019;,
  -0.009248;-0.999957;-0.000370;,
  0.000000;-1.000000;0.000331;,
  0.008342;-0.999965;-0.000019;,
  0.009248;-0.999957;-0.000370;,
  -0.986495;-0.056331;0.153799;,
  -0.998962;-0.045321;-0.004641;,
  -0.995512;-0.045339;-0.083067;,
  -0.994668;0.028050;0.099240;,
  0.986495;-0.056331;0.153799;,
  0.998962;-0.045321;-0.004641;,
  0.995512;-0.045339;-0.083067;,
  0.994024;0.025632;0.106109;;
  96;
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
  4;98,31,31,30;,
  4;31,32,32,31;,
  4;32,33,33,32;,
  4;33,99,34,33;,
  4;100,101,36,35;,
  4;101,102,37,36;,
  4;102,103,38,37;,
  4;103,104,39,38;,
  4;35,36,41,40;,
  4;36,37,42,41;,
  4;37,38,43,42;,
  4;38,39,44,43;,
  4;105,106,46,45;,
  4;106,107,47,46;,
  4;107,108,48,47;,
  4;108,109,49,48;,
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
  4;110,111,66,65;,
  4;111,112,67,66;,
  4;112,113,68,67;,
  4;113,114,69,68;,
  4;65,66,71,70;,
  4;66,67,72,71;,
  4;67,68,73,72;,
  4;68,69,74,73;,
  4;70,71,76,75;,
  4;71,72,77,76;,
  4;72,73,78,77;,
  4;73,74,79,78;,
  4;75,76,115,116;,
  4;76,77,117,115;,
  4;77,78,118,117;,
  4;78,79,119,118;,
  4;120,64,59,80;,
  4;121,120,80,81;,
  4;122,121,81,82;,
  4;4,122,82,9;,
  4;80,59,54,83;,
  4;81,80,83,84;,
  4;82,81,84,85;,
  4;9,82,85,14;,
  4;83,54,49,86;,
  4;84,83,86,87;,
  4;85,84,87,88;,
  4;14,85,88,19;,
  4;86,49,109,123;,
  4;87,86,123,34;,
  4;88,87,34,99;,
  4;19,88,29,24;,
  4;60,124,89,55;,
  4;124,125,90,89;,
  4;125,126,91,90;,
  4;126,0,5,91;,
  4;55,89,92,50;,
  4;89,90,93,92;,
  4;90,91,94,93;,
  4;91,5,10,94;,
  4;50,92,95,45;,
  4;92,93,96,95;,
  4;93,94,97,96;,
  4;94,10,15,97;,
  4;45,95,127,105;,
  4;95,96,30,127;,
  4;96,97,98,30;,
  4;97,15,20,25;;
 }
 MeshTextureCoords {
  98;
  0.158429;0.214358;,
  0.172834;0.214227;,
  0.172516;0.207341;,
  0.158110;0.207472;,
  0.190523;0.214109;,
  0.190523;0.207223;,
  0.208212;0.214227;,
  0.208530;0.207341;,
  0.222617;0.214358;,
  0.222936;0.207472;,
  0.172249;0.197257;,
  0.157844;0.197388;,
  0.190523;0.197139;,
  0.208797;0.197257;,
  0.223202;0.197388;,
  0.171982;0.187214;,
  0.157577;0.187345;,
  0.190523;0.187095;,
  0.209064;0.187214;,
  0.223469;0.187345;,
  0.171565;0.176936;,
  0.159701;0.178520;,
  0.190523;0.173058;,
  0.209481;0.176936;,
  0.221345;0.178520;,
  0.172700;0.168656;,
  0.158078;0.168802;,
  0.190523;0.168530;,
  0.208346;0.168656;,
  0.222968;0.168802;,
  0.176251;0.074176;,
  0.163432;0.073183;,
  0.190060;0.073900;,
  0.204834;0.074269;,
  0.217079;0.074599;,
  0.176225;0.075227;,
  0.156244;0.073335;,
  0.190523;0.075022;,
  0.204821;0.075227;,
  0.224535;0.074680;,
  0.176120;0.073412;,
  0.165610;0.073725;,
  0.190396;0.074138;,
  0.204483;0.074018;,
  0.215605;0.075158;,
  0.173172;0.186961;,
  0.160695;0.187213;,
  0.190523;0.186812;,
  0.207874;0.186961;,
  0.220351;0.187213;,
  0.172904;0.196924;,
  0.160427;0.197176;,
  0.190523;0.196775;,
  0.208142;0.196924;,
  0.220619;0.197176;,
  0.172640;0.207169;,
  0.160163;0.207422;,
  0.190523;0.207020;,
  0.208406;0.207169;,
  0.220883;0.207422;,
  0.172956;0.214216;,
  0.160731;0.214469;,
  0.190523;0.214067;,
  0.208090;0.214216;,
  0.220315;0.214469;,
  0.172834;0.214227;,
  0.155032;0.214459;,
  0.190523;0.214086;,
  0.208212;0.214227;,
  0.226014;0.214459;,
  0.172834;0.214227;,
  0.154362;0.214438;,
  0.190523;0.214086;,
  0.208212;0.214227;,
  0.226684;0.214438;,
  0.172834;0.214227;,
  0.155599;0.214405;,
  0.190523;0.214086;,
  0.208212;0.214227;,
  0.225447;0.214405;,
  0.226330;0.207413;,
  0.227000;0.207393;,
  0.225766;0.207518;,
  0.226066;0.197167;,
  0.226736;0.197146;,
  0.226032;0.197435;,
  0.225798;0.187204;,
  0.226468;0.187184;,
  0.226299;0.187391;,
  0.154716;0.207413;,
  0.154046;0.207393;,
  0.155281;0.207518;,
  0.154980;0.197167;,
  0.154310;0.197146;,
  0.155014;0.197435;,
  0.155248;0.187204;,
  0.154578;0.187184;,
  0.154747;0.187391;;
 }
}
