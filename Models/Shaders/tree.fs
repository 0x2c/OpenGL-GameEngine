#version 120

uniform sampler2D tex;

varying vec2 texturd;
void main() {
	gl_FragColor = texture2D(tex, texturd);
}