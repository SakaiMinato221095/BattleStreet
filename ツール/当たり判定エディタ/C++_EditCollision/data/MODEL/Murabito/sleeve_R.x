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
 0.76543;3.08405;2.20385;,
 8.91533;3.51651;3.20090;,
 8.83525;4.88993;-0.20279;,
 0.26773;4.38318;-0.01002;,
 8.75985;3.55019;-3.61998;,
 0.19928;3.53277;-3.08264;,
 17.49748;3.65008;3.61982;,
 17.40270;5.43399;-0.39539;,
 17.31403;3.68981;-4.42815;,
 17.53916;0.05343;5.15906;,
 17.41195;0.08101;-0.42203;,
 17.28473;0.10856;-6.00310;,
 17.51053;-2.88765;3.66442;,
 17.42023;-4.73063;-0.44599;,
 17.32355;-2.84713;-4.53784;,
 8.92640;-2.89999;3.16897;,
 8.85075;-4.09248;-0.24751;,
 8.77093;-2.86630;-3.65192;,
 0.34513;-2.91293;2.79873;,
 0.28238;-4.10825;-0.05227;,
 0.21545;-2.88483;-2.89121;,
 0.36415;0.03023;3.87080;,
 0.27520;0.04947;-0.03157;,
 0.18625;0.06877;-3.93392;,
 8.73665;0.08841;-4.91709;,
 8.95050;0.04209;4.46348;;
 
 24;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;1,6,7,2;,
 4;2,7,8,4;,
 4;6,9,10,7;,
 4;7,10,11,8;,
 4;9,12,13,10;,
 4;10,13,14,11;,
 4;12,15,16,13;,
 4;13,16,17,14;,
 4;15,18,19,16;,
 4;16,19,20,17;,
 4;18,21,22,19;,
 4;19,22,23,20;,
 4;21,0,3,22;,
 4;22,3,5,23;,
 4;23,24,17,20;,
 4;5,4,24,23;,
 4;24,11,14,17;,
 4;4,8,11,24;,
 4;18,15,25,21;,
 4;21,25,1,0;,
 4;15,12,9,25;,
 4;25,9,6,1;;
 
 MeshMaterialList {
  2;
  24;
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1;;
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
  42;
  -0.086970;0.692369;0.716283;,
  -0.060083;0.995728;0.070119;,
  -0.072294;0.698344;-0.712102;,
  -0.072165;0.694694;0.715676;,
  -0.057698;0.997603;0.038202;,
  -0.080992;0.701215;-0.708335;,
  -0.057018;0.696909;0.714889;,
  -0.055250;0.998453;0.006189;,
  -0.089373;0.703918;-0.704636;,
  0.999739;0.001841;-0.022782;,
  0.999739;0.001839;-0.022781;,
  0.999739;0.001838;-0.022779;,
  0.999739;0.001843;-0.022785;,
  0.999739;0.001839;-0.022782;,
  0.999739;0.001835;-0.022779;,
  -0.042433;-0.720225;0.692441;,
  -0.032485;-0.999463;-0.004197;,
  -0.074101;-0.713363;-0.696866;,
  -0.028613;-0.712335;0.701256;,
  -0.010107;-0.999938;-0.004710;,
  -0.060696;-0.705384;-0.706222;,
  -0.996794;0.034396;0.072236;,
  -0.998738;0.016269;0.047506;,
  -0.999739;-0.001839;0.022778;,
  -0.103752;-0.029698;-0.994160;,
  -0.074289;-0.005415;0.997222;,
  0.999739;0.001839;-0.022778;,
  0.999739;0.001840;-0.022779;,
  0.999739;0.001840;-0.022780;,
  -0.056026;-0.727760;0.683539;,
  -0.054950;-0.998482;-0.003681;,
  -0.087275;-0.720988;-0.687429;,
  -0.999739;-0.001836;0.022776;,
  -0.999739;-0.001838;0.022776;,
  -0.999739;-0.001840;0.022777;,
  -0.990094;0.070498;0.121425;,
  -0.996794;0.034395;0.072238;,
  -0.999739;-0.001838;0.022780;,
  -0.094397;-0.036096;-0.994880;,
  -0.113363;-0.023112;-0.993285;,
  -0.080513;0.022067;0.996509;,
  -0.067995;-0.032942;0.997142;;
  24;
  4;0,3,4,1;,
  4;1,4,5,2;,
  4;3,6,7,4;,
  4;4,7,8,5;,
  4;26,9,10,27;,
  4;27,10,11,28;,
  4;9,12,13,10;,
  4;10,13,14,11;,
  4;29,15,16,30;,
  4;30,16,17,31;,
  4;15,18,19,16;,
  4;16,19,20,17;,
  4;32,21,22,33;,
  4;33,22,23,34;,
  4;21,35,36,22;,
  4;22,36,37,23;,
  4;38,24,17,20;,
  4;2,5,24,38;,
  4;24,39,31,17;,
  4;5,8,39,24;,
  4;18,15,25,40;,
  4;40,25,3,0;,
  4;15,29,41,25;,
  4;25,41,6,3;;
 }
 MeshTextureCoords {
  26;
  0.952270;0.266640;,
  0.950004;0.292193;,
  0.982914;0.299543;,
  0.978097;0.269301;,
  0.986907;0.310555;,
  0.985472;0.278729;,
  0.947556;0.321283;,
  0.988128;0.329735;,
  0.991099;0.342948;,
  0.900881;0.321934;,
  0.931077;0.336959;,
  0.961273;0.351983;,
  0.877465;0.329897;,
  0.879795;0.343452;,
  0.921842;0.351978;,
  0.881618;0.300852;,
  0.887180;0.311665;,
  0.918521;0.319214;,
  0.885093;0.271469;,
  0.887596;0.280760;,
  0.915878;0.286787;,
  0.910795;0.264644;,
  0.931909;0.275149;,
  0.953022;0.285654;,
  0.956869;0.318680;,
  0.906116;0.293427;;
 }
}
