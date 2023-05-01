<h1>search_engine_v_0_1</h1>

<p>This search engine is a console application, that can be run on any server or computer. It's configurable via file "config.json", so you can change files' paths that the engine will search for.</p>

<h2>This project was created using the following technologies</h2>

<ul>
    <li><a href="https://en.cppreference.com/w/cpp/14#">C++14</a></li>
    <li><a href="https://cmake.org/cmake/help/latest/index.html">CMake 3.26.3</a></li>
    <li><a href="https://github.com/nlohmann/json">Nlohmann JSON Library</a></li>
    <li><a href="https://github.com/google/googletest">GoogleTest Framework</a></li>
    <li><a href="https://www.mingw-w64.org/">MinGW w64 12.2.0</a></li>
</ul>

<h2>How to build and run this app and test to it/h2>

<ul>
    <li>
        Download project in ZIP and then unpack it or clone this repository to your PC by command:
        <blockquote>
            <code>git clone https://github.com/IvanBorisov-RBST/search_engine_v_0_1.git</code></blockquote>
        and then go to folder of project
        <blockquote>
            <code>cd search_engine_v_0_1</code>
        </blockquote>
    </li>
    <li>
        Create folder for building app and go to it:
        <blockquote>
            <code>mkdir building</code><br/>
            <code>cd building</code>
        </blockquote>
    </li>
    <li>
        Input command:
        <blockquote>
            <code>cmake .. -G "MinGW Makefiles"</code><br/>
            <code>cmake --build . --config Release --target SearchEngine</code>
        </blockquote>
          if you get this messege "cmake: mingw32-make.exe No rule to make target", then use without --target;
          <blockquote>
             <code>cmake --build . --config Release</code>
          </blockquote>
    </li>
    <li>
        Go to source directory of build and run << .exe  >> file:
        <blockquote>
            <code>cd src</code><br/>
            <code>start  *.exe </code>
        </blockquote>
    </li>
</ul>

<h2>How does this engine work</h2>

<ul>
    <li>
        Before launching the app it's necessary to put text files paths you wanted to this engine for search by the "files" key of "config.json" file and your queries to "requests.json" file.<br/>
        For example:
        <h3>config.json</h3>
        <blockquote>
            <code>{
    "config": {
        "name": "Search Engine",
        "version": "0.1",
        "max_responses": 5
    },
    "files": [
        "../resources/file001.txt",
        "../resources/file002.txt",
        "../resources/file003.txt",
        "../resources/file004.txt"
    ]
}</code>
        </blockquote>
        <h3>requests.json</h3>
        <blockquote>
            <code>{
    "requests": [
        "word",
        "one more word",
        "another word",
        "too many words"
    ]
}</code>
        </blockquote>
    </li>
    <li>
        After running the app object of "ConverterJSON" class will be looking for "config.json" and "requests.json" files and will try to serialize them. If "config.json" or "requests.json" are missing or "config.json" is empty or programm version in "config.json" doesn't match with actual version, the engine will throw appropriate exception, else it will get required data to the private field of object such as text file paths and requests' strings.</li>
    <li>
        Then "InvertedIndex" class' object will parse .txt files from paths that "ConverterJSON" object got from "config.json" file to unique words and will count the number of entries of each word in each file.
    </li>
    <li>
        Finally "SearchServer" object will calculate the relative relevance for each requests in each file and counting results will be put in "answers.json" file.
    </li>
</ul>
