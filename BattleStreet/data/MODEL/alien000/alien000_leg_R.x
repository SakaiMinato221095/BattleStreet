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
 96;
 2.23325;-0.48134;3.80206;,
 -1.35213;-0.48134;3.97696;,
 2.10325;-24.37634;5.20056;,
 5.68879;-24.37634;5.02566;,
 -4.02853;-0.48134;1.58456;,
 -0.57314;-24.37634;2.80816;,
 0.05466;-57.74213;4.47516;,
 3.64017;-57.74213;4.30016;,
 -2.62160;-57.74213;2.08286;,
 -4.02853;-0.48134;1.58456;,
 -4.04632;-0.48134;-1.85604;,
 -0.59090;-24.37634;-0.63234;,
 -0.57314;-24.37634;2.80816;,
 -1.97421;-0.48134;-4.21664;,
 1.48130;-24.37634;-2.99304;,
 -2.63943;-57.74213;-1.35784;,
 -2.62160;-57.74213;2.08286;,
 -0.56722;-57.74213;-3.71844;,
 -1.97421;-0.48134;-4.21664;,
 1.65098;-0.48134;-4.50374;,
 5.10648;-24.37634;-3.28014;,
 1.48130;-24.37634;-2.99304;,
 4.28767;-0.48134;-1.99924;,
 7.74308;-24.37634;-0.77564;,
 3.05796;-57.74213;-4.00544;,
 -0.56722;-57.74213;-3.71844;,
 5.69459;-57.74213;-1.50104;,
 4.28767;-0.48134;-1.99924;,
 4.41248;-0.48134;1.13936;,
 7.86777;-24.37634;2.36296;,
 7.74308;-24.37634;-0.77564;,
 2.23325;-0.48134;3.80206;,
 5.68879;-24.37634;5.02566;,
 5.81928;-57.74213;1.63756;,
 5.69459;-57.74213;-1.50104;,
 3.64017;-57.74213;4.30016;,
 0.18308;-0.48134;-0.35824;,
 4.41248;-0.48134;1.13936;,
 -4.04632;-0.48134;-1.85604;,
 -1.35213;-0.48134;3.97696;,
 2.23325;-0.48134;3.80206;,
 -4.02853;-0.48134;1.58456;,
 5.81928;-57.74213;1.63756;,
 1.58997;-57.74213;0.13986;,
 -2.63943;-57.74213;-1.35784;,
 3.64017;-57.74213;4.30016;,
 0.05466;-57.74213;4.47516;,
 -2.62160;-57.74213;2.08286;,
 17.13306;-48.21053;-18.24624;,
 24.42149;-48.51393;-13.57504;,
 27.83768;-53.91383;-15.61144;,
 18.27396;-56.35883;-22.60984;,
 26.34827;-48.21053;-5.70814;,
 31.25419;-56.35883;-4.94894;,
 27.63047;-62.81892;-15.48794;,
 19.79926;-62.81892;-20.53454;,
 29.72886;-62.81892;-7.02424;,
 26.34827;-48.21053;-5.70814;,
 21.08768;-48.11303;0.95976;,
 22.52088;-56.35883;5.74686;,
 31.25419;-56.35883;-4.94894;,
 3.38340;-50.68873;7.52486;,
 3.93729;-56.35883;10.83346;,
 20.87257;-62.81892;3.50426;,
 29.72886;-62.81892;-7.02424;,
 -0.00954;-62.81892;10.01616;,
 3.38340;-50.68873;7.52486;,
 -3.87572;-48.92503;3.29196;,
 -8.35134;-56.35883;5.95966;,
 3.93729;-56.35883;10.83346;,
 -5.36602;-50.68873;-4.37974;,
 -8.53133;-56.35883;-6.13144;,
 -8.24691;-62.81892;5.89746;,
 -0.00954;-62.81892;10.01616;,
 -9.23821;-62.81892;-2.54034;,
 -5.36602;-50.68873;-4.37974;,
 8.26206;-48.11303;-16.49084;,
 3.92887;-56.35883;-19.54924;,
 -8.53133;-56.35883;-6.13144;,
 17.13306;-48.21053;-18.24624;,
 18.27396;-56.35883;-22.60984;,
 5.57706;-62.81892;-17.30674;,
 -9.23821;-62.81892;-2.54034;,
 19.79926;-62.81892;-20.53454;,
 15.89448;-45.26603;-8.49244;,
 8.26206;-48.11303;-16.49084;,
 21.08768;-48.11303;0.95976;,
 24.42149;-48.51393;-13.57504;,
 17.13306;-48.21053;-18.24624;,
 26.34827;-48.21053;-5.70814;,
 5.57706;-62.81892;-17.30674;,
 13.22489;-62.81892;-6.90124;,
 20.87257;-62.81892;3.50426;,
 19.79926;-62.81892;-20.53454;,
 27.63047;-62.81892;-15.48794;,
 29.72886;-62.81892;-7.02424;;
 
 48;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;3,2,6,7;,
 4;2,5,8,6;,
 4;9,10,11,12;,
 4;10,13,14,11;,
 4;12,11,15,16;,
 4;11,14,17,15;,
 4;18,19,20,21;,
 4;19,22,23,20;,
 4;21,20,24,25;,
 4;20,23,26,24;,
 4;27,28,29,30;,
 4;28,31,32,29;,
 4;30,29,33,34;,
 4;29,32,35,33;,
 4;27,19,36,37;,
 4;19,13,38,36;,
 4;37,36,39,40;,
 4;36,38,41,39;,
 4;42,43,24,34;,
 4;43,44,17,24;,
 4;45,46,43,42;,
 4;46,47,44,43;,
 4;48,49,50,51;,
 4;49,52,53,50;,
 4;51,50,54,55;,
 4;50,53,56,54;,
 4;57,58,59,60;,
 4;58,61,62,59;,
 4;60,59,63,64;,
 4;59,62,65,63;,
 4;66,67,68,69;,
 4;67,70,71,68;,
 4;69,68,72,73;,
 4;68,71,74,72;,
 4;75,76,77,78;,
 4;76,79,80,77;,
 4;78,77,81,82;,
 4;77,80,83,81;,
 4;75,67,84,85;,
 4;67,61,86,84;,
 4;85,84,87,88;,
 4;84,86,89,87;,
 4;90,91,72,82;,
 4;91,92,65,72;,
 4;93,94,91,90;,
 4;94,95,92,91;;
 
 MeshMaterialList {
  5;
  48;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
   1.000000;0.647000;0.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.090000;0.058230;0.000000;;
  }
  Material {
   0.800000;0.548800;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.840000;0.840000;0.840000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.060000;0.060000;0.060000;;
  }
  Material {
   0.432800;0.200800;0.153600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.524000;0.524000;0.524000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  53;
  0.445642;0.109938;0.888435;,
  -0.333811;-0.000001;0.942640;,
  0.448841;0.031579;0.893053;,
  -0.333808;-0.000001;0.942641;,
  0.449270;-0.046981;0.892160;,
  -0.333805;0.000000;0.942642;,
  -0.905442;-0.109939;0.409986;,
  -0.925886;-0.151612;-0.346047;,
  -0.910832;-0.031580;0.411567;,
  -0.935829;-0.043635;-0.349743;,
  -0.910601;0.046980;0.410607;,
  -0.934748;0.064984;-0.349319;,
  -0.443994;-0.109745;-0.889283;,
  0.333803;0.000001;-0.942643;,
  -0.447068;-0.031529;-0.893944;,
  0.333805;-0.000000;-0.942642;,
  -0.447392;0.046885;-0.893108;,
  0.333807;-0.000002;-0.942641;,
  0.904692;0.109744;-0.411691;,
  0.937322;0.151610;0.313754;,
  0.910017;0.031528;-0.413370;,
  0.947373;0.043633;0.317144;,
  0.909747;-0.046886;-0.412507;,
  0.946264;-0.064985;0.316798;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.129233;0.700074;-0.702279;,
  0.451711;0.828956;-0.329832;,
  0.186525;0.149407;-0.971023;,
  0.783789;0.252233;-0.567498;,
  0.205280;-0.232013;-0.950805;,
  0.809749;-0.073394;-0.582168;,
  0.664316;0.732777;0.147384;,
  0.333265;0.808305;0.485362;,
  0.964453;0.167793;0.204148;,
  0.549753;0.077134;0.831759;,
  0.951425;-0.253176;0.175195;,
  0.509335;-0.366583;0.778585;,
  -0.038833;0.701069;0.712035;,
  -0.432013;0.848666;0.305175;,
  -0.070998;0.197829;0.977662;,
  -0.776407;0.320430;0.542694;,
  -0.077382;-0.155044;0.984872;,
  -0.408006;0.045720;0.911834;,
  -0.639235;0.728051;-0.247629;,
  -0.276244;0.806590;-0.522591;,
  -0.918608;0.216078;-0.330861;,
  -0.482702;0.077380;-0.872360;,
  -0.930785;-0.164915;-0.326254;,
  -0.454893;-0.363883;-0.812811;,
  0.020005;0.999688;-0.014979;,
  0.000000;-1.000000;-0.000000;,
  -0.996567;0.050028;0.065957;;
  48;
  4;0,1,3,2;,
  4;1,6,8,3;,
  4;2,3,5,4;,
  4;3,8,10,5;,
  4;6,7,9,8;,
  4;7,12,14,9;,
  4;8,9,11,10;,
  4;9,14,16,11;,
  4;12,13,15,14;,
  4;13,18,20,15;,
  4;14,15,17,16;,
  4;15,20,22,17;,
  4;18,19,21,20;,
  4;19,0,2,21;,
  4;20,21,23,22;,
  4;21,2,4,23;,
  4;24,24,24,24;,
  4;24,24,24,24;,
  4;24,24,24,24;,
  4;24,24,24,24;,
  4;25,25,25,25;,
  4;25,25,25,25;,
  4;25,25,25,25;,
  4;25,25,25,25;,
  4;26,27,29,28;,
  4;27,32,34,29;,
  4;28,29,31,30;,
  4;29,34,36,31;,
  4;32,33,35,34;,
  4;33,38,40,35;,
  4;34,35,37,36;,
  4;35,40,42,37;,
  4;38,39,41,40;,
  4;39,44,46,41;,
  4;40,41,43,42;,
  4;41,46,48,52;,
  4;44,45,47,46;,
  4;45,26,28,47;,
  4;46,47,49,48;,
  4;47,28,30,49;,
  4;44,39,50,45;,
  4;39,38,33,50;,
  4;45,50,27,26;,
  4;50,33,32,27;,
  4;51,51,51,51;,
  4;51,51,51,51;,
  4;51,51,51,51;,
  4;51,51,51,51;;
 }
 MeshTextureCoords {
  96;
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.500000;,
  0.500000;0.500000;,
  1.000000;0.500000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.500000;,
  0.500000;0.500000;,
  1.000000;0.500000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  1.000000;0.000000;;
 }
}