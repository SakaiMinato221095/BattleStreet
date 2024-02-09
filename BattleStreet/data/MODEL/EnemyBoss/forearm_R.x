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
 26;
 -30.30883;-1.85983;3.03859;,
 -15.39703;-2.76434;3.50955;,
 -15.20935;1.76151;4.32729;,
 -30.17965;1.24911;3.87027;,
 -0.28484;-3.45293;3.90421;,
 -0.08873;1.27708;4.81201;,
 -15.11832;3.96158;3.74101;,
 -30.08361;3.57066;3.28279;,
 0.01805;3.85448;4.04303;,
 -15.14093;4.63890;-0.65054;,
 -30.10626;4.25456;-0.42112;,
 -0.00242;4.58136;-0.88081;,
 -15.21426;4.15663;-5.04182;,
 -30.17948;3.78049;-3.94509;,
 -0.08296;3.92472;-5.24730;,
 -15.33917;1.12378;-6.02962;,
 -30.26610;1.67387;-4.94203;,
 -0.21862;0.62937;-6.59841;,
 -15.50388;-2.83000;-4.96223;,
 -30.39004;-1.29371;-3.88433;,
 -0.38599;-3.38825;-5.45181;,
 -15.46426;-3.16316;-0.57561;,
 -30.19110;-2.24158;-0.45962;,
 -0.36285;-4.12020;-0.79705;,
 3.51823;1.15048;-0.87139;,
 -32.73654;1.83183;-0.41566;;
 
 24;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;3,2,6,7;,
 4;2,5,8,6;,
 4;7,6,9,10;,
 4;6,8,11,9;,
 4;10,9,12,13;,
 4;9,11,14,12;,
 4;13,12,15,16;,
 4;12,14,17,15;,
 4;16,15,18,19;,
 4;15,17,20,18;,
 4;19,18,21,22;,
 4;18,20,23,21;,
 4;22,21,1,0;,
 4;21,23,4,1;,
 4;23,20,17,24;,
 4;4,23,24,5;,
 4;24,17,14,11;,
 4;5,24,11,8;,
 4;19,22,25,16;,
 4;22,0,3,25;,
 4;16,25,10,13;,
 4;25,3,7,10;;
 
 MeshMaterialList {
  1;
  24;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
 }
 MeshNormals {
  50;
  -0.035047;-0.216769;0.975594;,
  -0.035325;-0.199218;0.979318;,
  -0.035591;-0.181603;0.982728;,
  -0.037142;0.018472;0.999139;,
  -0.032813;0.032573;0.998931;,
  -0.028486;0.046641;0.998505;,
  -0.037160;0.252681;0.966836;,
  -0.028526;0.262584;0.964487;,
  -0.019887;0.272440;0.961967;,
  -0.487276;0.872689;0.031246;,
  -0.011107;0.999797;0.016817;,
  0.006414;0.999928;0.010161;,
  -0.468144;0.852511;-0.232522;,
  -0.011293;0.992106;-0.124892;,
  0.463072;0.841848;-0.277228;,
  -0.080680;0.040897;-0.995901;,
  -0.055762;0.041386;-0.997586;,
  -0.031048;0.041845;-0.998642;,
  -0.088448;-0.293911;-0.951732;,
  -0.065717;-0.279878;-0.957784;,
  -0.042937;-0.265635;-0.963117;,
  -0.077299;-0.996460;-0.033060;,
  -0.065839;-0.997712;-0.015381;,
  -0.054377;-0.998518;0.002264;,
  0.999110;0.041666;-0.006520;,
  -0.995339;0.095568;0.012949;,
  -0.471852;0.830859;0.295008;,
  -0.010697;0.987352;0.158185;,
  0.005080;0.988792;0.149211;,
  -0.063707;0.371038;-0.926430;,
  -0.039958;0.358312;-0.932746;,
  -0.016179;0.345311;-0.938349;,
  -0.090702;-0.981678;-0.167575;,
  -0.071821;-0.987342;-0.141415;,
  -0.052862;-0.991946;-0.115103;,
  -0.058806;-0.992097;0.110838;,
  -0.062466;-0.992814;0.102067;,
  -0.055140;-0.991290;0.119599;,
  0.908619;-0.417611;-0.003510;,
  0.853926;-0.405918;-0.325639;,
  0.924006;0.041401;-0.380129;,
  0.866185;-0.384664;0.318994;,
  0.931131;0.036003;0.362902;,
  0.868171;0.496198;-0.008109;,
  0.825582;0.450077;0.340360;,
  -0.892083;-0.342097;-0.295224;,
  -0.936136;-0.351541;-0.008316;,
  -0.940022;0.099851;-0.326171;,
  -0.901229;-0.331334;0.279293;,
  -0.934722;0.080278;0.346194;;
  24;
  4;0,1,4,3;,
  4;1,2,5,4;,
  4;3,4,7,6;,
  4;4,5,8,7;,
  4;26,27,10,9;,
  4;27,28,11,10;,
  4;9,10,13,12;,
  4;10,11,14,13;,
  4;29,30,16,15;,
  4;30,31,17,16;,
  4;15,16,19,18;,
  4;16,17,20,19;,
  4;32,33,22,21;,
  4;33,34,23,22;,
  4;21,22,35,36;,
  4;22,23,37,35;,
  4;38,39,40,24;,
  4;41,38,24,42;,
  4;24,40,14,43;,
  4;42,24,43,44;,
  4;45,46,25,47;,
  4;46,48,49,25;,
  4;47,25,9,12;,
  4;25,49,26,9;;
 }
 MeshTextureCoords {
  26;
  0.817600;0.071430;,
  0.741630;0.077610;,
  0.740760;0.046690;,
  0.817030;0.050190;,
  0.664640;0.082310;,
  0.663730;0.050000;,
  0.740230;0.031660;,
  0.816470;0.034330;,
  0.663110;0.032400;,
  0.739880;0.027040;,
  0.816200;0.029660;,
  0.662690;0.027430;,
  0.739790;0.030330;,
  0.816200;0.032900;,
  0.662640;0.031920;,
  0.740320;0.051050;,
  0.816530;0.047290;,
  0.663190;0.054420;,
  0.741280;0.078050;,
  0.817280;0.067560;,
  0.664160;0.081870;,
  0.741540;0.080330;,
  0.816620;0.074030;,
  0.664530;0.086870;,
  0.644740;0.050860;,
  0.829600;0.046210;;
 }
}
