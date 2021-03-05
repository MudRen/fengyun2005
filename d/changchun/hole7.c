
inherit ROOM;
string *names=({
	__DIR__"hole7",
	__DIR__"hole5",
	__DIR__"hole1",
	__DIR__"hole6",
} );
void create()
{
	set("short", "洞穴");
	set("long", @LONG
山岩下秘洞，曲折深邃，有如诸葛武侯之八卦迷阵一般，幽谜繁复处尤有过之。
越是深入越是阴湿黝暗，到后来竟已难见五指。
LONG
	);
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",-20);
        set("no_magic",1);
        set("no_spells",1);
	setup();
}
void reset()
{
	int i,j;
	string temp;
	::reset();
	for (i=0;i<=3;i++)
	{
		j=random(4);
		temp=names[j];
		names[j]=names[i];
		names[i]=names[j];
		names[i]=temp;
	}
	set("exits", ([
		"north" : names[0],
		"south" : names[1],
		"east" : names[2],
		"west" : names[3],
	]));
}
