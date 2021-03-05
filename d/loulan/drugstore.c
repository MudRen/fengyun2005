inherit ROOM;

void create()
{
        set("short", "百草斋");
        set("long", @LONG
百草斋的主人叫卜公直，据传此人是哈密的瓜果巨子，不但有瓜田千顷，家资
巨万，轻功也算得是一流高手。这样的角色，竟然甘心在快活王的楼兰城里开了一
家普普通通的药草店，令人不得不感叹柴玉关的声势财富，已经不是凡人可以企望
的了。
LONG
        );

        set("exits", ([ 
		"south" : __DIR__"weststrt2",
	]));
        set("objects", ([
                __DIR__"npc/bu" : 1,
	]) );
        set("indoors", "loulan");

	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}
