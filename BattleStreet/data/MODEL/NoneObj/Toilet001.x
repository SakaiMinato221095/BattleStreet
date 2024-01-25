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
 220;
 365.30920;76.22549;-143.90080;,
 493.30899;76.22549;-143.90080;,
 493.30939;0.35010;-143.89999;,
 365.30960;0.35010;-143.89999;,
 -492.96619;76.22549;-143.90080;,
 -382.86221;76.22549;-143.90080;,
 -382.86179;0.35010;-143.89999;,
 -492.96600;0.35010;-143.89999;,
 588.33441;279.00690;195.31599;,
 493.30801;279.00690;246.72900;,
 493.30801;279.00690;143.90300;,
 536.92139;279.00690;143.90300;,
 588.33441;339.28430;195.31599;,
 493.30801;339.28430;246.72900;,
 493.30801;279.00690;246.72900;,
 588.33441;279.00690;195.31599;,
 588.33441;279.00690;-195.31599;,
 536.92139;279.00690;-143.90300;,
 588.33441;339.28430;-195.31599;,
 588.33441;279.00690;-195.31599;,
 493.30801;279.00690;-246.72900;,
 493.30801;279.00690;-143.90300;,
 493.30801;339.28430;-246.72900;,
 493.30801;279.00690;-246.72900;,
 -588.33441;279.00690;-195.31599;,
 -492.96719;279.00690;-246.72900;,
 -492.96719;279.00690;-143.90300;,
 -536.92139;279.00690;-143.90300;,
 -588.33441;339.28430;-195.31599;,
 -492.96719;339.28430;-246.72900;,
 -492.96719;279.00690;-246.72900;,
 -588.33441;279.00690;-195.31599;,
 -588.33441;279.00690;195.31599;,
 -536.92139;279.00690;143.90300;,
 -588.33441;339.28430;195.31599;,
 -588.33441;279.00690;195.31599;,
 -492.96719;279.00690;246.72900;,
 -492.96719;279.00690;143.90300;,
 -492.96719;339.28430;246.72900;,
 -492.96719;279.00690;246.72900;,
 178.77400;0.35211;31.16900;,
 306.61380;0.35211;31.16900;,
 306.61380;0.35010;-143.89999;,
 178.77400;0.35010;-143.89999;,
 306.61279;196.42450;31.16700;,
 178.77299;196.42450;31.16700;,
 178.77299;196.42250;-143.90221;,
 306.61279;196.42250;-143.90221;,
 -219.56960;196.42450;31.16700;,
 -322.87720;196.42450;31.16700;,
 -322.87720;196.42250;-143.90221;,
 -219.56960;196.42250;-143.90221;,
 -322.87619;0.35211;31.16900;,
 -219.56860;0.35211;31.16900;,
 -219.56860;0.35010;-143.89999;,
 -322.87619;0.35010;-143.89999;,
 365.30841;196.42270;-136.81059;,
 365.30920;76.22549;-136.80940;,
 365.30841;196.42250;-143.90221;,
 493.30841;196.42270;-136.81059;,
 493.30841;196.42250;-143.90221;,
 493.30899;76.22549;-136.80940;,
 365.30920;76.22549;-136.80940;,
 365.30841;196.42270;-136.81059;,
 493.30841;196.42270;-136.81059;,
 493.30899;76.22549;-136.80940;,
 -382.86279;196.42270;-136.81059;,
 -492.96680;196.42270;-136.81059;,
 -492.96680;196.42250;-143.90221;,
 -382.86279;196.42250;-143.90221;,
 -382.86221;76.22549;-136.80940;,
 -492.96619;76.22549;-136.80940;,
 -492.96680;196.42270;-136.81059;,
 -382.86279;196.42270;-136.81059;,
 -382.86221;76.22549;-136.80940;,
 -492.96619;76.22549;-136.80940;,
 276.30319;484.46509;-98.50300;,
 373.11099;484.46509;-98.50300;,
 373.11099;434.82568;-98.50300;,
 276.30319;434.82568;-98.50300;,
 276.30319;484.46509;98.50300;,
 276.30319;434.82568;98.50300;,
 373.11099;484.46509;98.50300;,
 373.11099;434.82568;98.50300;,
 -54.62480;484.46509;98.50300;,
 -54.62480;484.46509;-98.50300;,
 -54.62480;434.82568;-98.50300;,
 -54.62480;434.82568;98.50300;,
 82.64060;484.46509;98.50300;,
 82.64060;434.82568;98.50300;,
 82.64060;484.46509;-98.50300;,
 82.64060;434.82568;-98.50300;,
 263.72040;484.46509;-108.21140;,
 385.69379;484.46509;-108.21140;,
 373.11099;484.46509;-98.50300;,
 276.30319;484.46509;-98.50300;,
 263.72040;519.92194;-108.21140;,
 385.69379;519.92194;-108.21140;,
 263.72040;484.46509;108.21140;,
 263.72040;484.46509;-108.21140;,
 263.72040;519.92194;108.21140;,
 263.72040;484.46509;108.21140;,
 385.69379;484.46509;108.21140;,
 276.30319;484.46509;98.50300;,
 373.11099;484.46509;98.50300;,
 385.69379;519.92194;108.21140;,
 -67.20760;484.46509;108.21140;,
 -67.20760;484.46509;-108.21140;,
 -54.62480;484.46509;-98.50300;,
 -54.62480;484.46509;98.50300;,
 -67.20760;519.92194;108.21140;,
 -67.20760;519.92194;-108.21140;,
 95.22340;484.46509;108.21140;,
 82.64060;484.46509;98.50300;,
 95.22340;519.92194;108.21140;,
 95.22340;484.46509;-108.21140;,
 95.22340;484.46509;108.21140;,
 95.22340;519.92194;-108.21140;,
 95.22340;484.46509;-108.21140;,
 82.64060;484.46509;-98.50300;,
 -536.91998;0.35010;143.90601;,
 536.92279;0.35010;143.90601;,
 536.92279;0.35010;-143.89999;,
 493.30801;279.00690;-143.90300;,
 -536.91998;0.35010;-143.89999;,
 -492.96719;279.00690;-143.90300;,
 109.24760;0.35150;-18.91520;,
 -72.24540;0.35150;-18.91520;,
 -72.24640;196.42390;-18.91720;,
 109.24660;196.42390;-18.91720;,
 109.24660;196.42250;-143.90221;,
 109.24760;0.35010;-143.89999;,
 306.61380;0.35010;-143.89999;,
 -219.56860;0.35010;-143.89999;,
 -166.07800;0.35049;-128.62360;,
 -166.07800;0.35010;-143.89999;,
 -166.07899;196.42250;-143.90221;,
 -166.07899;196.42290;-128.62560;,
 -322.87619;0.35010;-143.89999;,
 -372.82059;434.82568;98.50300;,
 -372.82059;434.82568;-98.50300;,
 319.14182;207.96510;-143.90221;,
 319.14279;0.35010;-143.89999;,
 166.90440;207.96510;-143.90221;,
 178.77400;0.35010;-143.89999;,
 166.90540;0.35010;-143.89999;,
 166.90440;207.96510;-143.90221;,
 319.14182;207.96510;-143.90221;,
 -208.86819;207.96510;-143.90221;,
 -335.89081;207.96510;-143.90221;,
 119.34800;207.96510;-143.90221;,
 119.34920;0.35010;-143.89999;,
 -208.86819;207.96510;-143.90221;,
 -208.86720;0.35010;-143.89999;,
 -335.89081;207.96510;-143.90221;,
 -335.88980;0.35010;-143.89999;,
 -174.52960;207.96510;-143.90221;,
 -166.07800;0.35010;-143.89999;,
 -174.52859;0.35010;-143.89999;,
 -72.24640;196.42290;-128.62560;,
 -72.24540;0.35049;-128.62360;,
 319.14182;207.96510;-143.90221;,
 -335.89081;207.96510;-143.90221;,
 -174.52960;207.96510;-143.90221;,
 -166.07899;196.42290;-128.62560;,
 166.90480;127.93610;-143.90140;,
 119.34840;128.27670;-143.90140;,
 119.34820;173.22850;-143.90179;,
 166.90460;172.87790;-143.90179;,
 119.34820;173.22850;-143.90179;,
 166.90460;172.87790;-143.90179;,
 166.90480;127.93610;-143.90140;,
 119.34840;128.27670;-143.90140;,
 -174.52921;131.95590;-143.90140;,
 -174.52859;0.35010;-143.89999;,
 -208.86720;0.35010;-143.89999;,
 -208.86780;132.48930;-143.90140;,
 -208.86800;176.83830;-143.90179;,
 -208.86819;207.96510;-143.90221;,
 -174.52960;207.96510;-143.90221;,
 -174.52940;176.52090;-143.90179;,
 -208.86800;176.83830;-143.90179;,
 -174.52940;176.52090;-143.90179;,
 -174.52921;131.95590;-143.90140;,
 -208.86780;132.48930;-143.90140;,
 -166.07880;153.77069;-128.62520;,
 -72.24640;196.42290;-128.62560;,
 -72.24620;152.97729;-128.62520;,
 -72.24600;116.88930;-128.62480;,
 -72.24540;0.35049;-128.62360;,
 -166.07800;0.35049;-128.62360;,
 -166.07860;117.97089;-128.62480;,
 -72.24600;116.88930;-128.62480;,
 -166.07860;117.97089;-128.62480;,
 -166.07880;153.77069;-128.62520;,
 -72.24620;152.97729;-128.62520;,
 -276.30319;434.82568;-98.50300;,
 -372.82059;434.82568;-98.50300;,
 -373.11099;484.46509;-98.50300;,
 -276.30319;484.46509;-98.50300;,
 -276.30319;434.82568;98.50300;,
 -276.30319;484.46509;98.50300;,
 -372.82059;434.82568;98.50300;,
 -373.11099;484.46509;98.50300;,
 -276.30319;484.46509;-98.50300;,
 -373.11099;484.46509;-98.50300;,
 -385.69379;484.46509;-108.21140;,
 -263.72040;484.46509;-108.21140;,
 -385.69379;519.92194;-108.21140;,
 -263.72040;519.92194;-108.21140;,
 -263.72040;484.46509;-108.21140;,
 -263.72040;484.46509;108.21140;,
 -263.72040;484.46509;108.21140;,
 -263.72040;519.92194;108.21140;,
 -373.11099;484.46509;98.50300;,
 -276.30319;484.46509;98.50300;,
 -385.69379;484.46509;108.21140;,
 -385.69379;519.92194;108.21140;,
 -54.62480;434.82568;98.50300;,
 -54.62480;434.82568;-98.50300;;
 
 132;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;16,8,11,17;,
 4;18,12,15,19;,
 4;20,16,17,21;,
 4;22,18,19,23;,
 4;24,25,26,27;,
 4;28,29,30,31;,
 4;32,24,27,33;,
 4;34,28,31,35;,
 4;36,32,33,37;,
 4;38,34,35,39;,
 4;40,41,42,43;,
 4;44,45,46,47;,
 4;48,49,50,51;,
 4;52,53,54,55;,
 4;56,57,0,58;,
 4;59,56,58,60;,
 4;61,59,60,1;,
 4;57,61,1,0;,
 4;62,63,64,65;,
 4;66,67,68,69;,
 4;70,66,69,5;,
 4;71,70,5,4;,
 4;67,71,4,68;,
 4;72,73,74,75;,
 4;76,77,78,79;,
 4;80,76,79,81;,
 4;82,80,81,83;,
 4;77,82,83,78;,
 4;84,85,86,87;,
 4;88,84,87,89;,
 4;90,88,89,91;,
 4;85,90,91,86;,
 4;92,93,94,95;,
 4;96,97,93,92;,
 4;98,99,76,80;,
 4;100,96,92,101;,
 4;102,101,103,104;,
 4;105,100,101,102;,
 4;93,102,104,94;,
 4;97,105,102,93;,
 4;106,107,108,109;,
 4;110,111,107,106;,
 4;112,106,109,113;,
 4;114,110,106,112;,
 4;115,116,88,90;,
 4;117,114,112,118;,
 4;107,118,119,108;,
 4;111,117,118,107;,
 4;100,105,97,96;,
 4;114,117,111,110;,
 4;33,120,121,11;,
 4;17,11,121,122;,
 4;122,2,123,17;,
 4;7,124,27,125;,
 4;33,27,124,120;,
 4;126,127,128,129;,
 4;129,130,131,126;,
 4;40,43,46,45;,
 4;45,44,41,40;,
 4;44,47,132,41;,
 4;49,48,53,52;,
 4;48,51,133,53;,
 4;134,135,136,137;,
 4;52,55,50,49;,
 4;122,121,41,132;,
 4;133,53,52,138;,
 4;138,52,120,124;,
 4;120,52,41,121;,
 4;78,83,13,22;,
 4;13,12,18,22;,
 4;34,38,29,28;,
 4;139,140,29,38;,
 4;13,83,139,38;,
 4;78,22,29,140;,
 4;79,91,89,81;,
 4;38,39,14,13;,
 4;30,29,22,23;,
 4;20,21,26,25;,
 4;10,9,36,37;,
 4;141,58,3,142;,
 4;141,142,132,47;,
 4;143,46,144,145;,
 4;146,147,47,46;,
 4;148,51,50,149;,
 4;150,151,131,130;,
 4;152,153,133,51;,
 4;154,50,138,155;,
 4;154,155,6,69;,
 4;156,136,157,158;,
 4;159,130,129,128;,
 4;160,127,53,134;,
 4;157,134,53,133;,
 4;53,127,126,40;,
 4;144,40,126,131;,
 4;127,160,159,128;,
 4;41,40,144,132;,
 4;123,161,162,125;,
 4;150,130,136,163;,
 4;68,125,149,69;,
 4;123,60,58,141;,
 4;131,160,134,157;,
 4;126,127,160,131;,
 4;130,159,164,136;,
 4;126,131,160,127;,
 4;160,131,135,134;,
 4;165,145,151,166;,
 4;167,150,143,168;,
 4;169,170,171,172;,
 4;173,174,175,176;,
 4;177,178,179,180;,
 4;181,182,183,184;,
 4;185,164,186,187;,
 4;188,189,190,191;,
 4;192,193,194,195;,
 4;196,197,198,199;,
 4;200,196,199,201;,
 4;202,200,201,203;,
 4;197,202,203,198;,
 4;204,205,206,207;,
 4;207,206,208,209;,
 4;201,199,210,211;,
 4;212,207,209,213;,
 4;214,215,212,216;,
 4;216,212,213,217;,
 4;205,214,216,206;,
 4;206,216,217,208;,
 4;209,208,217,213;,
 4;200,218,219,196;;
 
 MeshMaterialList {
  9;
  132;
  0,
  0,
  0,
  5,
  0,
  5,
  0,
  5,
  0,
  5,
  0,
  5,
  0,
  5,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  3,
  0,
  0,
  0,
  0,
  4,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  0,
  1,
  5,
  1,
  0,
  1,
  0,
  1,
  0,
  1,
  0,
  1,
  5,
  1,
  0,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  2,
  0,
  0,
  2,
  0,
  2,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  7,
  0,
  0,
  6,
  0,
  0,
  8,
  5,
  5,
  5,
  5,
  0,
  1,
  5,
  1,
  0,
  1,
  0,
  1,
  1,
  5;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.153600;0.496000;0.511200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.558400;0.558400;0.558400;0.870000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\Glass.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\Glass.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\wood.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\toireman.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\toire.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\kurumaisu.png";
   }
  }
 }
 MeshNormals {
  114;
  0.000000;-1.000000;-0.000000;,
  0.000000;-0.000011;-1.000000;,
  1.000000;0.000005;0.000000;,
  0.000000;0.000011;1.000000;,
  1.000000;0.000005;-0.000000;,
  -1.000000;-0.000005;0.000000;,
  0.000000;-1.000000;0.000011;,
  0.000000;1.000000;-0.000012;,
  1.000000;0.000007;-0.000000;,
  -0.000001;-0.000011;-1.000000;,
  0.000000;-1.000000;0.000028;,
  0.000000;-0.000011;-1.000000;,
  0.000000;-0.000011;-1.000000;,
  0.000000;1.000000;-0.000012;,
  0.000000;-1.000000;0.000028;,
  0.000000;-0.000011;-1.000000;,
  0.000001;-0.000011;-1.000000;,
  0.000000;-0.000011;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.478658;-0.878002;,
  0.000000;0.478658;0.878002;,
  -0.341808;0.891429;-0.297527;,
  -0.341808;0.891429;0.297527;,
  -0.474539;0.000000;-0.880234;,
  0.475856;0.000000;0.879523;,
  0.245435;0.000000;-0.969413;,
  0.245435;0.000000;0.969413;,
  -0.244710;0.000000;-0.969596;,
  -0.244710;0.000000;0.969596;,
  0.000000;-0.000010;-1.000000;,
  -1.000000;-0.000005;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000001;-0.000008;-1.000000;,
  0.000002;-0.000011;-1.000000;,
  -0.000003;-0.000011;-1.000000;,
  -0.000002;-0.000008;-1.000000;,
  0.000002;-0.000008;-1.000000;,
  0.000002;-0.000008;-1.000000;,
  -0.000001;-0.000008;-1.000000;,
  0.000003;-0.000011;-1.000000;,
  -0.000000;-1.000000;0.000015;,
  0.000003;-0.000011;-1.000000;,
  -0.000002;-0.000011;-1.000000;,
  -0.000002;-0.000008;-1.000000;,
  -0.000004;-0.000011;-1.000000;,
  -0.000000;-1.000000;0.000018;,
  -0.000000;-0.000010;-1.000000;,
  -0.000000;-0.000010;-1.000000;,
  -0.000000;-0.000010;-1.000000;,
  -0.000000;-0.000011;-1.000000;,
  -0.000000;-0.000010;-1.000000;,
  -0.000000;-0.000011;-1.000000;,
  0.475856;0.000000;-0.879523;,
  -0.474539;0.000000;0.880234;,
  0.000000;-0.000010;-1.000000;,
  1.000000;0.000005;-0.000000;,
  0.900623;0.434601;0.000000;,
  -0.000000;-0.000010;-1.000000;,
  0.000000;-0.000009;-1.000000;,
  -1.000000;-0.000005;0.000000;,
  1.000000;0.000005;-0.000000;,
  0.000000;-0.000010;-1.000000;,
  -1.000000;-0.000005;0.000000;,
  0.000000;-0.000010;-1.000000;,
  -1.000000;-0.000005;0.000000;,
  -0.000007;-1.000000;0.000006;,
  -0.000004;-1.000000;-0.000006;,
  -0.000002;-1.000000;-0.000000;,
  -0.000004;-1.000000;0.000009;,
  0.000001;-1.000000;0.000015;,
  0.000000;-1.000000;0.000013;,
  0.000002;-1.000000;-0.000000;,
  0.000002;-1.000000;0.000009;,
  0.000002;-1.000000;-0.000006;,
  0.000005;-1.000000;0.000006;,
  0.226268;0.953935;0.197006;,
  0.226268;0.953935;-0.197006;,
  -0.226334;0.953918;0.197012;,
  -0.226334;0.953918;-0.197012;,
  -0.000001;-0.000010;-1.000000;,
  0.000005;-0.000011;-1.000000;,
  0.000002;-0.000005;-1.000000;,
  -0.000003;-0.000005;-1.000000;,
  -0.000005;-0.000011;-1.000000;,
  0.000003;-0.000005;-1.000000;,
  -0.000002;-0.000005;-1.000000;,
  0.000006;-0.000011;-1.000000;,
  0.000003;-0.000005;-1.000000;,
  0.000006;-0.000011;-1.000000;,
  -0.000005;-0.000011;-1.000000;,
  0.000001;-0.000008;-1.000000;,
  -0.000004;-0.000005;-1.000000;,
  -0.000007;-0.000011;-1.000000;,
  -0.000001;-1.000000;0.000010;,
  -0.000000;-1.000000;0.000011;,
  0.000001;-1.000000;0.000018;,
  0.000001;-1.000000;0.000022;,
  -0.000000;-1.000000;0.000011;,
  0.000000;-1.000000;0.000012;,
  0.000000;-1.000000;0.000011;,
  -0.000000;-1.000000;0.000016;,
  1.000000;0.000005;-0.000000;,
  0.000000;-0.000005;-1.000000;,
  -0.000001;-0.000008;-1.000000;,
  0.000000;-1.000000;0.000026;,
  0.000001;1.000000;-0.000010;,
  0.000000;1.000000;-0.000018;,
  0.000000;1.000000;-0.000026;,
  -0.000000;-0.000009;-1.000000;,
  -0.000000;-0.000010;-1.000000;,
  -0.999983;-0.005850;0.000000;;
  132;
  4;12,12,11,9;,
  4;15,15,16,17;,
  4;0,0,0,0;,
  4;27,29,29,27;,
  4;0,0,0,0;,
  4;18,18,18,18;,
  4;0,0,0,0;,
  4;28,55,55,28;,
  4;0,0,0,0;,
  4;26,30,30,26;,
  4;0,0,0,0;,
  4;21,21,21,21;,
  4;0,0,0,0;,
  4;31,56,56,31;,
  4;7,7,7,7;,
  4;6,6,6,6;,
  4;6,6,6,6;,
  4;13,13,13,13;,
  4;8,8,8,8;,
  4;10,10,10,10;,
  4;33,33,33,33;,
  4;34,34,34,34;,
  4;57,57,57,57;,
  4;14,14,14,14;,
  4;33,33,33,33;,
  4;34,34,34,34;,
  4;58,58,58,58;,
  4;57,57,57,57;,
  4;20,20,22,20;,
  4;21,21,21,21;,
  4;19,19,19,23;,
  4;18,18,59,59;,
  4;21,21,21,21;,
  4;19,19,19,19;,
  4;18,18,18,18;,
  4;20,20,20,20;,
  4;0,0,0,0;,
  4;20,20,20,20;,
  4;0,0,0,0;,
  4;21,21,21,21;,
  4;0,0,0,0;,
  4;19,19,19,19;,
  4;0,0,0,0;,
  4;18,18,18,18;,
  4;0,0,0,0;,
  4;21,21,21,21;,
  4;0,0,0,0;,
  4;19,19,19,19;,
  4;0,0,0,0;,
  4;18,18,18,18;,
  4;0,0,0,0;,
  4;20,20,20,20;,
  4;34,34,34,34;,
  4;34,34,34,34;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;1,11,60,1;,
  4;17,1,1,61;,
  4;62,62,62,62;,
  4;32,32,32,32;,
  4;5,5,5,5;,
  4;63,63,63,63;,
  4;64,64,64,64;,
  4;65,65,65,65;,
  4;66,66,66,66;,
  4;67,67,67,67;,
  4;4,4,4,4;,
  4;63,63,63,63;,
  4;68,69,70,71;,
  4;72,73,74,75;,
  4;75,74,76,77;,
  4;76,74,70,69;,
  4;59,59,78,79;,
  4;78,34,34,79;,
  4;34,80,81,34;,
  4;25,24,81,80;,
  4;78,23,25,80;,
  4;22,79,81,24;,
  4;34,34,34,34;,
  4;31,31,29,29;,
  4;30,30,28,28;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;35,82,9,36;,
  4;35,36,83,84;,
  4;38,85,86,37;,
  4;38,35,84,85;,
  4;40,87,88,41;,
  4;39,42,89,90;,
  4;40,44,91,87;,
  4;41,88,92,45;,
  4;41,45,16,93;,
  4;46,94,95,47;,
  4;48,48,96,96;,
  4;43,97,73,98;,
  4;99,98,73,72;,
  4;73,97,100,101;,
  4;102,101,100,103;,
  4;104,104,104,104;,
  4;70,101,102,71;,
  4;60,35,41,61;,
  4;39,90,94,46;,
  4;105,61,41,93;,
  4;60,106,82,35;,
  4;103,43,98,99;,
  4;100,97,43,103;,
  4;48,48,107,107;,
  4;108,109,109,108;,
  4;109,109,110,110;,
  4;49,37,42,49;,
  4;50,39,38,50;,
  4;50,50,49,49;,
  4;51,47,44,51;,
  4;52,40,46,52;,
  4;52,52,51,51;,
  4;53,111,111,53;,
  4;54,112,112,54;,
  4;54,54,53,53;,
  4;20,20,20,20;,
  4;18,18,18,18;,
  4;19,19,19,19;,
  4;113,113,113,113;,
  4;0,0,0,0;,
  4;20,20,20,20;,
  4;0,0,0,0;,
  4;18,18,18,18;,
  4;0,0,0,0;,
  4;19,19,19,19;,
  4;0,0,0,0;,
  4;21,21,21,21;,
  4;34,34,34,34;,
  4;34,34,34,34;;
 }
 MeshTextureCoords {
  220;
  0.840190;0.727710;,
  0.959390;0.727710;,
  0.959390;1.000000;,
  0.840190;1.000000;,
  0.040930;0.727710;,
  0.143460;0.727710;,
  0.143460;1.000000;,
  0.040930;1.000000;,
  1.000000;0.000000;,
  0.959390;0.000000;,
  0.959390;0.000000;,
  1.000000;0.000000;,
  0.333183;0.869298;,
  0.345810;0.966509;,
  0.331836;0.966509;,
  0.320400;0.869298;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.333183;0.130702;,
  0.320400;0.130702;,
  0.959390;1.000000;,
  0.959390;1.000000;,
  0.345810;0.033491;,
  0.331836;0.033491;,
  0.000000;1.000000;,
  0.040930;1.000000;,
  0.040930;1.000000;,
  0.000000;1.000000;,
  0.666817;0.130702;,
  0.654139;0.033491;,
  0.668117;0.033491;,
  0.679600;0.130702;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.666817;0.869298;,
  0.679600;0.869298;,
  0.040930;0.000000;,
  0.040930;0.000000;,
  0.654139;0.966509;,
  0.668117;0.966509;,
  0.666480;1.000000;,
  0.785530;1.000000;,
  0.785530;1.000000;,
  0.666480;1.000000;,
  0.785530;0.296370;,
  0.666480;0.296370;,
  0.666480;0.296370;,
  0.785530;0.296370;,
  0.295530;0.296370;,
  0.199330;0.296370;,
  0.199330;0.296370;,
  0.295530;0.296370;,
  0.199330;1.000000;,
  0.295530;1.000000;,
  0.295530;1.000000;,
  0.199330;1.000000;,
  0.840190;0.296370;,
  0.840190;0.727710;,
  0.840190;0.296370;,
  0.959390;0.296370;,
  0.959390;0.296370;,
  0.959390;0.727710;,
  -0.038563;0.868361;,
  -0.038576;-0.968618;,
  1.977172;-0.968618;,
  1.977181;0.868361;,
  0.143460;0.296370;,
  0.040930;0.296370;,
  0.040930;0.296370;,
  0.143460;0.296370;,
  0.143460;0.727710;,
  0.040930;0.727710;,
  0.149531;-0.968618;,
  1.883452;-0.968618;,
  1.883461;0.868361;,
  0.149540;0.868361;,
  0.417458;0.313753;,
  0.395495;0.313753;,
  0.387070;0.313753;,
  0.409849;0.313753;,
  0.417458;0.686247;,
  0.409849;0.686247;,
  0.395495;0.686247;,
  0.387070;0.686247;,
  0.517883;0.686247;,
  0.517883;0.313753;,
  0.519905;0.313753;,
  0.519905;0.686247;,
  0.473091;0.686247;,
  0.470085;0.686247;,
  0.473091;0.313753;,
  0.470085;0.313753;,
  0.840190;1.000000;,
  0.959390;1.000000;,
  0.959390;1.000000;,
  0.840190;1.000000;,
  0.840190;1.000000;,
  0.959390;1.000000;,
  0.420613;0.704603;,
  0.420613;0.295397;,
  0.840190;0.000000;,
  0.840190;0.000000;,
  0.959390;0.000000;,
  0.840190;0.000000;,
  0.959390;0.000000;,
  0.959390;0.000000;,
  0.432720;0.000000;,
  0.432720;1.000000;,
  0.432720;1.000000;,
  0.432720;0.000000;,
  0.432720;0.000000;,
  0.432720;1.000000;,
  0.601730;0.000000;,
  0.601730;0.000000;,
  0.601730;0.000000;,
  0.469089;0.295397;,
  0.469089;0.704603;,
  0.601730;1.000000;,
  0.601730;1.000000;,
  0.601730;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.959390;0.000000;,
  0.000000;0.000000;,
  0.040930;0.000000;,
  0.601730;1.000000;,
  0.432720;1.000000;,
  0.432720;0.296370;,
  0.601730;0.296370;,
  0.601730;0.296370;,
  0.601730;0.000000;,
  0.785530;0.000000;,
  0.295530;0.000000;,
  0.345340;1.000000;,
  0.345340;1.000000;,
  0.345340;0.296370;,
  0.345340;0.296370;,
  0.199330;0.000000;,
  0.612869;0.686247;,
  0.612869;0.313753;,
  0.797200;0.296370;,
  0.797200;0.213460;,
  0.655430;0.296370;,
  0.666480;0.000000;,
  0.655430;0.000000;,
  0.666480;0.254940;,
  0.785530;0.254940;,
  0.295530;0.254940;,
  0.199330;0.254940;,
  0.611140;0.296370;,
  0.611140;0.000000;,
  0.305490;0.296370;,
  0.305490;0.000000;,
  0.187210;0.296370;,
  0.187210;0.216950;,
  0.337470;0.296370;,
  0.345340;0.000000;,
  0.337470;0.000000;,
  0.432720;0.296370;,
  0.432720;1.000000;,
  0.797200;0.254940;,
  0.187210;0.254940;,
  0.345340;0.254940;,
  0.360260;0.296370;,
  0.655430;0.182130;,
  0.611140;0.182610;,
  0.611140;0.246780;,
  0.655430;0.246280;,
  0.012940;-0.004541;,
  1.048576;0.003248;,
  1.048580;1.001688;,
  0.012944;0.994121;,
  0.934270;0.791020;,
  0.934290;1.738170;,
  -0.015800;1.738170;,
  -0.015810;0.787180;,
  -0.015820;0.468010;,
  -0.015820;0.243990;,
  0.934260;0.243990;,
  0.934270;0.470290;,
  -0.015770;-0.004489;,
  0.934279;0.002354;,
  0.934285;0.963221;,
  -0.015765;0.951720;,
  0.360260;0.449430;,
  0.420030;0.296370;,
  0.420030;0.452280;,
  0.420030;0.581790;,
  0.420030;1.000000;,
  0.360260;1.000000;,
  0.360260;0.577900;,
  1.117954;0.957357;,
  -0.074450;0.929726;,
  -0.074452;0.015160;,
  1.117951;0.035428;,
  0.590150;0.313753;,
  0.612869;0.313753;,
  0.604505;0.313753;,
  0.582542;0.313753;,
  0.590150;0.686247;,
  0.582542;0.686247;,
  0.612869;0.686247;,
  0.604505;0.686247;,
  0.840190;1.000000;,
  0.959390;1.000000;,
  0.959390;1.000000;,
  0.840190;1.000000;,
  0.959390;1.000000;,
  0.840190;1.000000;,
  0.579387;0.295397;,
  0.579387;0.704603;,
  0.840190;0.000000;,
  0.840190;0.000000;,
  0.959390;0.000000;,
  0.840190;0.000000;,
  0.959390;0.000000;,
  0.959390;0.000000;,
  0.519905;0.686247;,
  0.519905;0.313753;;
 }
}