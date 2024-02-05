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
 48;
 -7.09920;2.18931;-17.93568;,
 0.87865;1.88591;-21.29645;,
 1.13535;-3.51399;-25.26529;,
 -10.04918;-5.95899;-21.34753;,
 8.45332;2.18931;-18.42851;,
 11.85773;-5.95899;-22.04158;,
 1.11978;-12.41909;-25.02458;,
 -7.47492;-12.41909;-21.42910;,
 9.28349;-12.41909;-21.96001;,
 8.45332;2.18931;-18.42851;,
 10.96888;2.28681;-10.31637;,
 15.72583;-5.95899;-8.78607;,
 11.85773;-5.95899;-22.04158;,
 6.35152;-0.28889;7.99272;,
 9.39196;-5.95899;9.41025;,
 12.94404;-12.41909;-8.69789;,
 9.28349;-12.41909;-21.96001;,
 6.48291;-12.41909;12.19999;,
 6.35152;-0.28889;7.99272;,
 -1.24852;1.47481;11.57759;,
 -1.58501;-5.95899;16.77704;,
 9.39196;-5.95899;9.41025;,
 -8.41509;-0.28889;8.46049;,
 -11.65156;-5.95899;10.07693;,
 -1.57714;-12.41909;16.65577;,
 6.48291;-12.41909;12.19999;,
 -9.09242;-12.41909;12.69351;,
 -8.41509;-0.28889;8.46049;,
 -10.67713;2.28681;-9.63059;,
 -15.65198;-5.95899;-7.79178;,
 -11.65156;-5.95899;10.07693;,
 -7.09920;2.18931;-17.93568;,
 -10.04918;-5.95899;-21.34753;,
 -12.87033;-12.41909;-7.87994;,
 -9.09242;-12.41909;12.69351;,
 -7.47492;-12.41909;-21.42910;,
 0.23761;5.13381;-11.39031;,
 -10.67713;2.28681;-9.63059;,
 10.96888;2.28681;-10.31637;,
 0.87865;1.88591;-21.29645;,
 -7.09920;2.18931;-17.93568;,
 8.45332;2.18931;-18.42851;,
 -12.87033;-12.41909;-7.87994;,
 0.03688;-12.41909;-8.28895;,
 12.94404;-12.41909;-8.69789;,
 -7.47492;-12.41909;-21.42910;,
 1.11978;-12.41909;-25.02458;,
 9.28349;-12.41909;-21.96001;;
 
 24;
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
 4;46,47,44,43;;
 
 MeshMaterialList {
  5;
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
  27;
  -0.505567;0.700075;-0.504278;,
  -0.015970;0.828956;-0.559085;,
  -0.694597;0.149409;-0.703713;,
  -0.023745;0.252235;-0.967375;,
  -0.667311;-0.232013;-0.707718;,
  -0.021131;-0.073392;-0.997079;,
  0.497736;0.732777;-0.464000;,
  0.588764;0.808305;0.000260;,
  0.714516;0.167795;-0.679200;,
  0.996857;0.077135;0.018048;,
  0.683277;-0.253173;-0.684862;,
  0.930143;-0.366582;0.021239;,
  0.564811;0.701069;0.435305;,
  0.006808;0.848665;0.528887;,
  0.765503;0.197829;0.612266;,
  0.007487;0.320429;0.947243;,
  0.767829;-0.155044;0.621611;,
  0.520368;0.045720;0.852717;,
  -0.566144;0.728051;0.386552;,
  -0.587147;0.806591;-0.068339;,
  -0.792976;0.216079;0.569648;,
  -0.992340;0.077380;-0.096302;,
  -0.796077;-0.164913;0.582293;,
  -0.927513;-0.363884;-0.085491;,
  -0.001014;0.999688;-0.024971;,
  0.000000;-1.000000;-0.000000;,
  -0.510103;0.050032;0.858657;;
  24;
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
  4;15,20,22,26;,
  4;18,19,21,20;,
  4;19,0,2,21;,
  4;20,21,23,22;,
  4;21,2,4,23;,
  4;18,13,24,19;,
  4;13,12,7,24;,
  4;19,24,1,0;,
  4;24,7,6,1;,
  4;25,25,25,25;,
  4;25,25,25,25;,
  4;25,25,25,25;,
  4;25,25,25,25;;
 }
 MeshTextureCoords {
  48;
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