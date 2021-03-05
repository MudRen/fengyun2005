#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "西耳房");
        set("long", @LONG
扑鼻一股脂粉香气,木几上点着一根红烛，红烛旁是一面明镜，一只梳妆箱子。
房中放着一张大床，透过纱帐看去，床上铺着绣花的锦被和枕头。大红锦被上绣的
是一对戏水鸳鸯，颜色灿烂，栩栩欲活。床前地下两对绣花拖鞋，一对男的，一对
女的，并排而置。
LONG
        );
        set("exits", ([ 
		"east": __DIR__"redhouse0",
	]));
        set("item_desc", ([
		"bed": 	"大床吱吱嘎嘎地摇晃着，锦被下似乎有人在蠕动，
你是不是要过去（ａｐｐｒｏａｃｈ）看一下呢？\n",
		"床": 	"大床吱吱嘎嘎地摇晃着，锦被下似乎有人在蠕动，
你是不是要过去（ａｐｐｒｏａｃｈ）看一下呢？\n",
		"mirror":	"你对着镜子照了照，发现自己在风云里又老了一岁。\n",
		"镜":		"你对着镜子照了照，发现自己在风云里又老了一岁。\n",
		"箱子":		"箱子锁得紧紧地，不可能打开。\n",
	 ]));
        set("objects", ([
        	
        ]));
	set("coor/x",-90);
	set("coor/y",-50);
	set("coor/z",10);
	set("map","taiping");
	set("yuanwai",1);
	setup();
}


void 	init(){
	add_action("do_approach","approach");
}


int	do_approach(string arg){
	object piaoke,me;
	me=this_player();
	piaoke=present("piaoke",this_object());
	if (piaoke && !userp(piaoke))
		return notify_fail("上官磷说：“怎么没规没矩的，快快出去！”\n");
	if (!arg || (arg!="bed" && arg!="床"))
		return notify_fail("你要走近哪里？\n");
	message_vision(YEL"$N走近大床，探头探脑地向帐中看去。\n",me);
	if (!query("yuanwai"))
		tell_object(me,"床上一个女子睡得正熟，锦被外露出一双春笋般的小手。\n");
	
	message_vision(HIR"一声尖叫，一声怒喝，床上跳出个精赤的大汉！\n"NOR,me);
	piaoke=new(__DIR__"npc/piaoke2");
	piaoke->move(this_object());
	if (me->query("gender")=="女性")
		message_vision("上官磷忽然咧嘴一笑说：“怎么，妈妈叫你也来陪大爷？”\n",me);
	else message_vision("上官磷说：“小子，搅了大爷的兴致，快滚出去！”\n",me);
	return 1;
}



