var fs = require("fs");
var cp = require("child_process");

var filedata = fs.readFileSync("packaging.json").toString();
var packaging = JSON.parse(filedata);
var packerPath = "/Users/louis/Projects/emscripten/emsdk_portable/emscripten/tag-1.34.1/tools/file_packager.py";

var exclusion = [];
for (var i = 0; i < packaging.length; ++i) {
	var fileArgs = packaging[i];
	var cpArgs = [
		packerPath,
		"./build/asset" + i + ".data",
		'--preload'
	];

	cpArgs = cpArgs.concat(fileArgs);

	if (i > 0) {
		cpArgs.push('--exclude');
		cpArgs = cpArgs.concat(exclusion);
	}

	var s = cp.spawn("python", cpArgs);
	s.stdout.pipe(fs.createWriteStream("./build/asset" + i + ".js"));

	s.stderr.on('data', function (d) {
		console.error("err", d.toString());
	});

	s.on('close', function (code) {
		  console.log('child process exited with code ' + code);
	});

	exclusion = exclusion.concat(fileArgs);
}
