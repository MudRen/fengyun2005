inherit __DIR__"no_killing_place";
void create()
{
    set("short", "小河西岸");
    set("long", @LONG
河边是青青的草地，几株水仙长在浅浅的岸边，随风轻柔的摆动。河面不宽，
水流也不湍急，哗啦啦的流水声似乎是在唱着一首欢快的歌曲。一座精巧的小拱桥
连接着两岸。河岸的对面是碧绿的草坪，四周种植着一些树，隐约可见几间精致的
小屋坐落其间。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
        "west" : __DIR__"road5",
        "east" : __DIR__"bridge",
        ]));
	set("no_magic", 1);
    set("outdoors","taoyuan");
	set("coor/x",50);
	set("coor/y",0);
	set("coor/z",0);
    setup();
        replace_program( __DIR__"no_killing_place");
}


