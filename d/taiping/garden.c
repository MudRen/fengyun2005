inherit ROOM;
void create()
{
        set("short", "花圃");
        set("long", @LONG
西风满院，败叶满径。院子里栽有几棵芭蕉。“深怕数秋更，况复秋声彻夜惊。
第一雁声听不得，才听，又是秋虫第一声。凄绝梦回程，冷雨愁花伴小庭。遥想故
人千里外，关情，一样疏窗一样灯”，冷萧萧，笆蕉风碎，你的心亦似被摇曳在风
中的芭蕉叶割碎了。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"corridor3",
		"south": __DIR__"pavilion",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
	        
	]));
	set("coor/x",-100);
	set("coor/y",-40);
	set("coor/z",0);
	set("map","taiping");
	setup();
}


