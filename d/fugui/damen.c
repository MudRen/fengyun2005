inherit ROOM;

void create()
{
	set("short", "富贵山庄大门");
	set("long", @LONG
路到尽头，便是闻名天下的『富贵山庄』的大门。乍一望去，大门梁上雕龙刻
凤，美奂美仑，不知凝聚着多少能工巧匠的心血。不禁让人以为庄主定是富有显贵
之人。门前左右各蹲着一只威武庄严的石狮子。但定睛细瞧，则让人喟叹不己，原
来门上锈迹斑斑，满是灰尘，红漆也已剥落大半，莫名之中让人产生一种凄凉的感
觉。
LONG);

	set("outdoors", "fugui");
	set("type","street");
	set("exits",([
        "southdown":__DIR__"shandao1",
        "enter":__DIR__"suishilu1",
	]) );
	set("bandit_out",1);
	set("coor/x",10);
	set("coor/y",190);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}

/*
void init() {
	int i;
	i=sizeof(query("coor"));
	message_vision("size of coor is"+(string)(i)+".\n",this_player());
}
*/