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
 390;
 -348.92911;223.33189;-166.87711;,
 247.07780;223.33189;-166.87711;,
 247.07780;5.68730;-166.87711;,
 -348.92911;5.68730;-166.87711;,
 247.07780;223.33189;-166.87711;,
 247.07780;223.33189;251.53770;,
 247.07780;5.68730;251.53770;,
 247.07780;5.68730;-166.87711;,
 247.07780;223.33189;251.53770;,
 -348.92911;223.33189;251.53770;,
 -348.92911;5.68730;251.53770;,
 247.07780;5.68730;251.53770;,
 -348.92911;223.33189;251.53770;,
 -348.92911;223.33189;-166.87711;,
 -348.92911;5.68730;-166.87711;,
 -348.92911;5.68730;251.53770;,
 247.07780;223.33189;-166.87711;,
 -348.92911;223.33189;-166.87711;,
 -348.92911;5.68730;-166.87711;,
 247.07780;5.68730;-166.87711;,
 -348.92911;287.66809;-332.29211;,
 378.52899;287.66809;-332.29211;,
 378.52899;221.09280;-332.29211;,
 -348.92911;221.09280;-332.29211;,
 378.52899;287.66809;-332.29211;,
 378.52899;287.66809;254.76910;,
 378.52899;221.09280;254.76910;,
 378.52899;221.09280;-332.29211;,
 378.52899;287.66809;254.76910;,
 -348.92911;287.66809;254.76910;,
 -348.92911;221.09280;254.76910;,
 378.52899;221.09280;254.76910;,
 -348.92911;287.66809;254.76910;,
 -348.92911;287.66809;-332.29211;,
 -348.92911;221.09280;-332.29211;,
 -348.92911;221.09280;254.76910;,
 378.52899;287.66809;-332.29211;,
 -348.92911;287.66809;-332.29211;,
 -348.92911;221.09280;-332.29211;,
 378.52899;221.09280;-332.29211;,
 -342.10471;477.53650;-265.32831;,
 378.52899;477.53650;-265.32831;,
 378.52899;289.22131;-265.32831;,
 -342.10471;289.22131;-265.32831;,
 378.52899;477.53650;-265.32831;,
 378.52899;477.53650;254.76910;,
 378.52899;289.22131;254.76910;,
 378.52899;289.22131;-265.32831;,
 378.52899;477.53650;254.76910;,
 -342.10471;477.53650;254.76910;,
 -342.10471;289.22131;254.76910;,
 378.52899;289.22131;254.76910;,
 -342.10471;477.53650;254.76910;,
 -342.10471;477.53650;-265.32831;,
 -342.10471;289.22131;-265.32831;,
 -342.10471;289.22131;254.76910;,
 378.52899;477.53650;-265.32831;,
 -342.10471;477.53650;-265.32831;,
 -342.10471;289.22131;-265.32831;,
 378.52899;289.22131;-265.32831;,
 -291.77689;195.64861;167.39011;,
 -287.79999;300.90591;224.26691;,
 -141.22701;300.28979;213.46220;,
 -152.98550;198.11340;158.96030;,
 -273.26871;203.65891;170.80510;,
 -260.28189;321.24011;234.32170;,
 -148.56790;322.47250;227.09190;,
 -270.38321;337.26099;244.50681;,
 -125.00930;322.47250;225.41380;,
 -141.03140;224.60941;173.76410;,
 250.51640;218.90820;-265.32831;,
 378.52899;218.90820;-265.32831;,
 378.52899;6.12860;-265.32831;,
 250.51640;6.12860;-265.32831;,
 378.52899;218.90820;-265.32831;,
 378.52899;218.90820;254.76910;,
 378.52899;6.12860;254.76910;,
 378.52899;6.12860;-265.32831;,
 378.52899;218.90820;254.76910;,
 250.51640;218.90820;254.76910;,
 250.51640;6.12860;254.76910;,
 378.52899;6.12860;254.76910;,
 250.51640;218.90820;254.76910;,
 250.51640;218.90820;-265.32831;,
 250.51640;6.12860;-265.32831;,
 250.51640;6.12860;254.76910;,
 378.52899;218.90820;-265.32831;,
 250.51640;218.90820;-265.32831;,
 250.51640;6.12860;-265.32831;,
 378.52899;6.12860;-265.32831;,
 -345.91901;35.14390;-238.53349;,
 -295.59439;35.14390;-238.53349;,
 -295.59439;7.12000;-238.53349;,
 -345.91901;7.12000;-238.53349;,
 -295.59439;35.14390;-238.53349;,
 -295.59439;35.14390;-179.94730;,
 -295.59439;7.12000;-179.94730;,
 -295.59439;7.12000;-238.53349;,
 -295.59439;35.14390;-179.94730;,
 -345.91901;35.14390;-179.94730;,
 -345.91901;7.12000;-179.94730;,
 -295.59439;7.12000;-179.94730;,
 -345.91901;35.14390;-179.94730;,
 -345.91901;35.14390;-238.53349;,
 -345.91901;7.12000;-238.53349;,
 -345.91901;7.12000;-179.94730;,
 -295.59439;35.14390;-238.53349;,
 -345.91901;35.14390;-238.53349;,
 -345.91901;7.12000;-238.53349;,
 -295.59439;7.12000;-238.53349;,
 -282.21979;35.14390;-238.53349;,
 -231.89571;35.14390;-238.53349;,
 -231.89571;7.12000;-238.53349;,
 -282.21979;7.12000;-238.53349;,
 -231.89571;35.14390;-238.53349;,
 -231.89571;35.14390;-179.94730;,
 -231.89571;7.12000;-179.94730;,
 -231.89571;7.12000;-238.53349;,
 -231.89571;35.14390;-179.94730;,
 -282.21979;35.14390;-179.94730;,
 -282.21979;7.12000;-179.94730;,
 -231.89571;7.12000;-179.94730;,
 -282.21979;35.14390;-179.94730;,
 -282.21979;35.14390;-238.53349;,
 -282.21979;7.12000;-238.53349;,
 -282.21979;7.12000;-179.94730;,
 -231.89571;35.14390;-238.53349;,
 -282.21979;35.14390;-238.53349;,
 -282.21979;7.12000;-238.53349;,
 -231.89571;7.12000;-238.53349;,
 -282.21979;35.14390;-313.39249;,
 -231.89571;35.14390;-313.39249;,
 -231.89571;7.12000;-313.39249;,
 -282.21979;7.12000;-313.39249;,
 -231.89571;35.14390;-313.39249;,
 -231.89571;35.14390;-254.80670;,
 -231.89571;7.12000;-254.80670;,
 -231.89571;7.12000;-313.39249;,
 -231.89571;35.14390;-254.80670;,
 -282.21979;35.14390;-254.80670;,
 -282.21979;7.12000;-254.80670;,
 -231.89571;7.12000;-254.80670;,
 -282.21979;35.14390;-254.80670;,
 -282.21979;35.14390;-313.39249;,
 -282.21979;7.12000;-313.39249;,
 -282.21979;7.12000;-254.80670;,
 -231.89571;35.14390;-313.39249;,
 -282.21979;35.14390;-313.39249;,
 -282.21979;7.12000;-313.39249;,
 -231.89571;7.12000;-313.39249;,
 -345.16821;35.14390;-313.39249;,
 -294.84369;35.14390;-313.39249;,
 -294.84369;7.12000;-313.39249;,
 -345.16821;7.12000;-313.39249;,
 -294.84369;35.14390;-313.39249;,
 -294.84369;35.14390;-254.80670;,
 -294.84369;7.12000;-254.80670;,
 -294.84369;7.12000;-313.39249;,
 -294.84369;35.14390;-254.80670;,
 -345.16821;35.14390;-254.80670;,
 -345.16821;7.12000;-254.80670;,
 -294.84369;7.12000;-254.80670;,
 -345.16821;35.14390;-254.80670;,
 -345.16821;35.14390;-313.39249;,
 -345.16821;7.12000;-313.39249;,
 -345.16821;7.12000;-254.80670;,
 -294.84369;35.14390;-313.39249;,
 -345.16821;35.14390;-313.39249;,
 -345.16821;7.12000;-313.39249;,
 -294.84369;7.12000;-313.39249;,
 -345.91901;63.90350;-238.53349;,
 -295.59439;63.90350;-238.53349;,
 -295.59439;35.87960;-238.53349;,
 -345.91901;35.87960;-238.53349;,
 -295.59439;63.90350;-238.53349;,
 -295.59439;63.90350;-179.94730;,
 -295.59439;35.87960;-179.94730;,
 -295.59439;35.87960;-238.53349;,
 -295.59439;63.90350;-179.94730;,
 -345.91901;63.90350;-179.94730;,
 -345.91901;35.87960;-179.94730;,
 -295.59439;35.87960;-179.94730;,
 -345.91901;63.90350;-179.94730;,
 -345.91901;63.90350;-238.53349;,
 -345.91901;35.87960;-238.53349;,
 -345.91901;35.87960;-179.94730;,
 -295.59439;63.90350;-238.53349;,
 -345.91901;63.90350;-238.53349;,
 -345.91901;35.87960;-238.53349;,
 -295.59439;35.87960;-238.53349;,
 -345.16821;63.90350;-313.39249;,
 -294.84369;63.90350;-313.39249;,
 -294.84369;35.87960;-313.39249;,
 -345.16821;35.87960;-313.39249;,
 -294.84369;63.90350;-313.39249;,
 -294.84369;63.90350;-254.80670;,
 -294.84369;35.87960;-254.80670;,
 -294.84369;35.87960;-313.39249;,
 -294.84369;63.90350;-254.80670;,
 -345.16821;63.90350;-254.80670;,
 -345.16821;35.87960;-254.80670;,
 -294.84369;35.87960;-254.80670;,
 -345.16821;63.90350;-254.80670;,
 -345.16821;63.90350;-313.39249;,
 -345.16821;35.87960;-313.39249;,
 -345.16821;35.87960;-254.80670;,
 -294.84369;63.90350;-313.39249;,
 -345.16821;63.90350;-313.39249;,
 -345.16821;35.87960;-313.39249;,
 -294.84369;35.87960;-313.39249;,
 129.00960;35.14390;-257.53110;,
 179.33400;35.14390;-257.53110;,
 179.33400;7.12000;-257.53110;,
 129.00960;7.12000;-257.53110;,
 179.33400;35.14390;-257.53110;,
 179.33400;35.14390;-198.94479;,
 179.33400;7.12000;-198.94479;,
 179.33400;7.12000;-257.53110;,
 179.33400;35.14390;-198.94479;,
 129.00960;35.14390;-198.94479;,
 129.00960;7.12000;-198.94479;,
 179.33400;7.12000;-198.94479;,
 129.00960;35.14390;-198.94479;,
 129.00960;35.14390;-257.53110;,
 129.00960;7.12000;-257.53110;,
 129.00960;7.12000;-198.94479;,
 179.33400;35.14390;-257.53110;,
 129.00960;35.14390;-257.53110;,
 129.00960;7.12000;-257.53110;,
 179.33400;7.12000;-257.53110;,
 187.58620;35.14390;-258.72879;,
 237.91051;35.14390;-258.72879;,
 237.91051;7.12000;-258.72879;,
 187.58620;7.12000;-258.72879;,
 237.91051;35.14390;-258.72879;,
 237.91051;35.14390;-200.14240;,
 237.91051;7.12000;-200.14240;,
 237.91051;7.12000;-258.72879;,
 237.91051;35.14390;-200.14240;,
 187.58620;35.14390;-200.14240;,
 187.58620;7.12000;-200.14240;,
 237.91051;7.12000;-200.14240;,
 187.58620;35.14390;-200.14240;,
 187.58620;35.14390;-258.72879;,
 187.58620;7.12000;-258.72879;,
 187.58620;7.12000;-200.14240;,
 237.91051;35.14390;-258.72879;,
 187.58620;35.14390;-258.72879;,
 187.58620;7.12000;-258.72879;,
 237.91051;7.12000;-258.72879;,
 187.58620;64.41050;-258.72879;,
 237.91051;64.41050;-258.72879;,
 237.91051;36.38670;-258.72879;,
 187.58620;36.38670;-258.72879;,
 237.91051;64.41050;-258.72879;,
 237.91051;64.41050;-200.14240;,
 237.91051;36.38670;-200.14240;,
 237.91051;36.38670;-258.72879;,
 237.91051;64.41050;-200.14240;,
 187.58620;64.41050;-200.14240;,
 187.58620;36.38670;-200.14240;,
 237.91051;36.38670;-200.14240;,
 187.58620;64.41050;-200.14240;,
 187.58620;64.41050;-258.72879;,
 187.58620;36.38670;-258.72879;,
 187.58620;36.38670;-200.14240;,
 237.91051;64.41050;-258.72879;,
 187.58620;64.41050;-258.72879;,
 187.58620;36.38670;-258.72879;,
 237.91051;36.38670;-258.72879;,
 -277.37781;37.86560;-230.67799;,
 -238.34560;37.86560;-230.67799;,
 -238.34560;31.24420;-230.67799;,
 -277.37781;31.24420;-230.67799;,
 -238.34560;37.86560;-230.67799;,
 -238.34560;37.86560;-186.26649;,
 -238.34560;31.24420;-186.26649;,
 -238.34560;31.24420;-230.67799;,
 -238.34560;37.86560;-186.26649;,
 -277.37781;37.86560;-186.26649;,
 -277.37781;31.24420;-186.26649;,
 -238.34560;31.24420;-186.26649;,
 -277.37781;37.86560;-186.26649;,
 -277.37781;37.86560;-230.67799;,
 -277.37781;31.24420;-230.67799;,
 -277.37781;31.24420;-186.26649;,
 -238.34560;37.86560;-230.67799;,
 -277.37781;37.86560;-230.67799;,
 -277.37781;31.24420;-230.67799;,
 -238.34560;31.24420;-230.67799;,
 -340.85669;75.93940;-313.35199;,
 -328.92389;75.93940;-317.96689;,
 -328.92389;69.31790;-317.96689;,
 -340.85669;69.31790;-313.35199;,
 -328.92389;75.93940;-317.96689;,
 -319.84860;59.35260;-275.27600;,
 -319.84860;52.73130;-275.27600;,
 -328.92389;69.31790;-317.96689;,
 -319.84860;59.35260;-275.27600;,
 -331.78101;59.35260;-270.66071;,
 -331.78101;52.73130;-270.66071;,
 -319.84860;52.73130;-275.27600;,
 -331.78101;59.35260;-270.66071;,
 -340.85669;75.93940;-313.35199;,
 -340.85669;69.31790;-313.35199;,
 -331.78101;52.73130;-270.66071;,
 -328.92389;75.93940;-317.96689;,
 -340.85669;75.93940;-313.35199;,
 -340.85669;69.31790;-313.35199;,
 -328.92389;69.31790;-317.96689;,
 -294.19260;75.93940;-310.24210;,
 -289.64310;75.93940;-294.66299;,
 -289.64310;69.31790;-294.66299;,
 -294.19260;69.31790;-310.24210;,
 -289.64310;75.93940;-294.66299;,
 -320.27740;59.35260;-278.38629;,
 -320.27740;52.73130;-278.38629;,
 -289.64310;69.31790;-294.66299;,
 -320.27740;59.35260;-278.38629;,
 -324.82681;59.35260;-293.96509;,
 -324.82681;52.73130;-293.96509;,
 -320.27740;52.73130;-278.38629;,
 -324.82681;59.35260;-293.96509;,
 -294.19260;75.93940;-310.24210;,
 -294.19260;69.31790;-310.24210;,
 -324.82681;52.73130;-293.96509;,
 -289.64310;75.93940;-294.66299;,
 -294.19260;75.93940;-310.24210;,
 -294.19260;69.31790;-310.24210;,
 -289.64310;69.31790;-294.66299;,
 -324.12369;80.14980;-294.69901;,
 -315.99780;76.84990;-305.84299;,
 -320.35229;71.06930;-305.95380;,
 -328.47839;74.36910;-294.80939;,
 -315.99780;76.84990;-305.84299;,
 -307.88300;54.30130;-272.97580;,
 -312.23849;48.52070;-273.08661;,
 -320.35229;71.06930;-305.95380;,
 -307.88300;54.30130;-272.97580;,
 -316.00931;57.60110;-261.83179;,
 -320.36380;51.82060;-261.94260;,
 -312.23849;48.52070;-273.08661;,
 -316.00931;57.60110;-261.83179;,
 -324.12369;80.14980;-294.69901;,
 -328.47839;74.36910;-294.80939;,
 -320.36380;51.82060;-261.94260;,
 -315.99780;76.84990;-305.84299;,
 -324.12369;80.14980;-294.69901;,
 -328.47839;74.36910;-294.80939;,
 -320.35229;71.06930;-305.95380;,
 -348.92911;409.09491;-278.14151;,
 122.96200;409.09491;-278.14151;,
 122.96200;291.14850;-278.14151;,
 -348.92911;291.14850;-278.14151;,
 122.96200;409.09491;-278.14151;,
 122.96200;409.09491;251.53770;,
 122.96200;291.14850;251.53770;,
 122.96200;291.14850;-278.14151;,
 122.96200;409.09491;251.53770;,
 -348.92911;409.09491;251.53770;,
 -348.92911;291.14850;251.53770;,
 122.96200;291.14850;251.53770;,
 -348.92911;409.09491;251.53770;,
 -348.92911;409.09491;-278.14151;,
 -348.92911;291.14850;-278.14151;,
 -348.92911;291.14850;251.53770;,
 122.96200;409.09491;-278.14151;,
 -348.92911;409.09491;-278.14151;,
 -348.92911;291.14850;-278.14151;,
 122.96200;291.14850;-278.14151;,
 -295.89700;170.19569;-176.33310;,
 167.87531;169.21030;-176.34320;,
 167.87531;5.80070;-176.34320;,
 -295.89700;6.78600;-176.33310;,
 167.87531;169.21030;-176.34320;,
 172.84531;161.67990;242.08160;,
 172.84531;6.78600;242.08160;,
 167.87531;5.80070;-176.34320;,
 172.84531;161.67990;242.08160;,
 -295.89700;161.67990;242.08160;,
 -295.89700;6.78600;242.08160;,
 172.84531;6.78600;242.08160;,
 -295.89700;161.67990;242.08160;,
 -295.89700;170.19569;-176.33310;,
 -295.89700;6.78600;-176.33310;,
 -295.89700;6.78600;242.08160;,
 167.87531;169.21030;-176.34320;,
 -295.89700;170.19569;-176.33310;,
 -295.89700;6.78600;-176.33310;,
 167.87531;5.80070;-176.34320;;
 
 117;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;12,5,16,17;,
 4;18,19,6,15;,
 4;20,21,22,23;,
 4;24,25,26,27;,
 4;28,29,30,31;,
 4;32,33,34,35;,
 4;32,25,36,37;,
 4;38,39,26,35;,
 4;40,41,42,43;,
 4;44,45,46,47;,
 4;48,49,50,51;,
 4;52,53,54,55;,
 4;52,45,56,57;,
 4;58,59,46,55;,
 4;60,61,62,63;,
 4;64,65,66,63;,
 4;64,67,68,69;,
 4;70,71,72,73;,
 4;74,75,76,77;,
 4;78,79,80,81;,
 4;82,83,84,85;,
 4;82,75,86,87;,
 4;88,89,76,85;,
 4;90,91,92,93;,
 4;94,95,96,97;,
 4;98,99,100,101;,
 4;102,103,104,105;,
 4;102,95,106,107;,
 4;108,109,96,105;,
 4;110,111,112,113;,
 4;114,115,116,117;,
 4;118,119,120,121;,
 4;122,123,124,125;,
 4;122,115,126,127;,
 4;128,129,116,125;,
 4;130,131,132,133;,
 4;134,135,136,137;,
 4;138,139,140,141;,
 4;142,143,144,145;,
 4;142,135,146,147;,
 4;148,149,136,145;,
 4;150,151,152,153;,
 4;154,155,156,157;,
 4;158,159,160,161;,
 4;162,163,164,165;,
 4;162,155,166,167;,
 4;168,169,156,165;,
 4;170,171,172,173;,
 4;174,175,176,177;,
 4;178,179,180,181;,
 4;182,183,184,185;,
 4;182,175,186,187;,
 4;188,189,176,185;,
 4;190,191,192,193;,
 4;194,195,196,197;,
 4;198,199,200,201;,
 4;202,203,204,205;,
 4;202,195,206,207;,
 4;208,209,196,205;,
 4;210,211,212,213;,
 4;214,215,216,217;,
 4;218,219,220,221;,
 4;222,223,224,225;,
 4;222,215,226,227;,
 4;228,229,216,225;,
 4;230,231,232,233;,
 4;234,235,236,237;,
 4;238,239,240,241;,
 4;242,243,244,245;,
 4;242,235,246,247;,
 4;248,249,236,245;,
 4;250,251,252,253;,
 4;254,255,256,257;,
 4;258,259,260,261;,
 4;262,263,264,265;,
 4;262,255,266,267;,
 4;268,269,256,265;,
 4;270,271,272,273;,
 4;274,275,276,277;,
 4;278,279,280,281;,
 4;282,283,284,285;,
 4;282,275,286,287;,
 4;288,289,276,285;,
 4;290,291,292,293;,
 4;294,295,296,297;,
 4;298,299,300,301;,
 4;302,303,304,305;,
 4;302,295,306,307;,
 4;308,309,296,305;,
 4;310,311,312,313;,
 4;314,315,316,317;,
 4;318,319,320,321;,
 4;322,323,324,325;,
 4;322,315,326,327;,
 4;328,329,316,325;,
 4;330,331,332,333;,
 4;334,335,336,337;,
 4;338,339,340,341;,
 4;342,343,344,345;,
 4;342,335,346,347;,
 4;348,349,336,345;,
 4;350,351,352,353;,
 4;354,355,356,357;,
 4;358,359,360,361;,
 4;362,363,364,365;,
 4;362,355,366,367;,
 4;368,369,356,365;,
 4;370,371,372,373;,
 4;374,375,376,377;,
 4;378,379,380,381;,
 4;382,383,384,385;,
 4;382,375,386,387;,
 4;388,389,376,385;;
 
 MeshMaterialList {
  8;
  117;
  4,
  4,
  4,
  4,
  7,
  7,
  5,
  3,
  3,
  3,
  3,
  3,
  4,
  4,
  4,
  4,
  4,
  7,
  3,
  3,
  3,
  4,
  4,
  4,
  4,
  4,
  4,
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
  1,
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
  1,
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
  1,
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
  1,
  0,
  0,
  0,
  0,
  0,
  1,
  0,
  2,
  2,
  2,
  2,
  2,
  1,
  3,
  3,
  2,
  3,
  3,
  3,
  3,
  2,
  2,
  3,
  3,
  1,
  3,
  3,
  2,
  3,
  3,
  3,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  4,
  4,
  4,
  4,
  4;;
  Material {
   0.800000;0.624000;0.448800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.304000;0.235200;0.169600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.548800;0.671200;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.128800;0.238400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.310400;0.341600;0.357600;1.000000;;
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
    "data\\TEXTURE\\obamart000.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\doar000.png";
   }
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  107;
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -0.062213;0.475807;-0.877347;,
  -0.062594;0.478160;-0.876039;,
  -0.062974;0.480510;-0.874725;,
  -0.062500;0.479625;-0.875245;,
  -0.062025;0.478740;-0.875763;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  -0.360705;0.000000;-0.932680;,
  0.978143;0.000000;-0.207935;,
  0.360743;0.000000;0.932665;,
  -0.978141;0.000000;0.207942;,
  0.129584;0.933248;0.335048;,
  -0.129583;-0.933249;-0.335044;,
  0.959907;0.000000;-0.280318;,
  0.469205;0.000000;0.883089;,
  -0.959907;0.000000;0.280318;,
  -0.469213;0.000000;-0.883085;,
  -0.421188;0.898594;0.122998;,
  0.421184;-0.898597;-0.122997;,
  -0.630880;0.486804;-0.604163;,
  0.687732;-0.508187;-0.518431;,
  0.630849;-0.486855;0.604154;,
  -0.687746;0.508169;0.518429;,
  0.677783;0.673585;0.294777;,
  -0.677804;-0.673568;-0.294768;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  -0.000022;0.000000;-1.000000;,
  0.999929;0.000000;-0.011877;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.001062;0.999816;0.019171;,
  -0.001062;-0.999999;0.001190;;
  117;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;9,9,9,9;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;12,12,12,12;,
  4;13,13,13,13;,
  4;14,14,14,14;,
  4;20,20,20,20;,
  4;21,21,21,21;,
  4;22,22,22,22;,
  4;15,15,15,16;,
  4;18,17,17,16;,
  4;18,19,19,19;,
  4;23,23,23,23;,
  4;24,24,24,24;,
  4;25,25,25,25;,
  4;26,26,26,26;,
  4;27,27,27,27;,
  4;28,28,28,28;,
  4;29,29,29,29;,
  4;30,30,30,30;,
  4;31,31,31,31;,
  4;32,32,32,32;,
  4;33,33,33,33;,
  4;34,34,34,34;,
  4;35,35,35,35;,
  4;36,36,36,36;,
  4;37,37,37,37;,
  4;38,38,38,38;,
  4;39,39,39,39;,
  4;40,40,40,40;,
  4;41,41,41,41;,
  4;42,42,42,42;,
  4;43,43,43,43;,
  4;44,44,44,44;,
  4;45,45,45,45;,
  4;46,46,46,46;,
  4;47,47,47,47;,
  4;48,48,48,48;,
  4;49,49,49,49;,
  4;50,50,50,50;,
  4;51,51,51,51;,
  4;52,52,52,52;,
  4;53,53,53,53;,
  4;54,54,54,54;,
  4;55,55,55,55;,
  4;56,56,56,56;,
  4;57,57,57,57;,
  4;58,58,58,58;,
  4;53,53,53,53;,
  4;54,54,54,54;,
  4;55,55,55,55;,
  4;56,56,56,56;,
  4;57,57,57,57;,
  4;58,58,58,58;,
  4;59,59,59,59;,
  4;60,60,60,60;,
  4;61,61,61,61;,
  4;62,62,62,62;,
  4;63,63,63,63;,
  4;64,64,64,64;,
  4;59,59,59,59;,
  4;60,60,60,60;,
  4;61,61,61,61;,
  4;62,62,62,62;,
  4;63,63,63,63;,
  4;64,64,64,64;,
  4;65,65,65,65;,
  4;66,66,66,66;,
  4;67,67,67,67;,
  4;68,68,68,68;,
  4;69,69,69,69;,
  4;70,70,70,70;,
  4;71,71,71,71;,
  4;72,72,72,72;,
  4;73,73,73,73;,
  4;74,74,74,74;,
  4;75,75,75,75;,
  4;76,76,76,76;,
  4;77,77,77,77;,
  4;78,78,78,78;,
  4;79,79,79,79;,
  4;80,80,80,80;,
  4;81,81,81,81;,
  4;82,82,82,82;,
  4;83,83,83,83;,
  4;84,84,84,84;,
  4;85,85,85,85;,
  4;86,86,86,86;,
  4;87,87,87,87;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;90,90,90,90;,
  4;91,91,91,91;,
  4;92,92,92,92;,
  4;93,93,93,93;,
  4;94,94,94,94;,
  4;95,95,95,95;,
  4;96,96,96,96;,
  4;97,97,97,97;,
  4;98,98,98,98;,
  4;99,99,99,99;,
  4;100,100,100,100;,
  4;101,101,101,101;,
  4;102,102,102,102;,
  4;103,103,103,103;,
  4;104,104,104,104;,
  4;105,105,105,105;,
  4;106,106,106,106;;
 }
 MeshTextureCoords {
  390;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.187090;,
  1.823870;0.187090;,
  1.823870;1.005940;,
  0.000000;1.005940;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;;
 }
}