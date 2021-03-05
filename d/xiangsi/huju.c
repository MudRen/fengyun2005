// annie 07.2003
// dancingfaery@hotmail.com

#include <ansi.h>
inherit ROOM;
string tree();

void create()
{
    set("short", "虎踞石");
    set("long", @LONG
走到这里，两侧的山壁渐渐合拢，道路更见崎岖。空气中带着些须潮气，
山壁上爬满了喜湿的青萝石苔。抬头上望，只见十数丈高处一座石梁飞跨两山
左右，梁下一块形如猛虎的大石盘踞，正对着石梁作势欲扑。(ｊｕｍｐ ｕｐ) 
LONG
    );
    set("objects", ([
	__DIR__"obj/rock2" : 1,
	__DIR__"obj/stone" : 1,
      ]));
    set("exits",([
	"north" : __DIR__"qingxi",
	"south" : __DIR__"shuangtian",
      ]) );



    set("item_desc", ([
		"cliff" : (: tree :),
		"山壁" : (: tree :),
		"青萝石苔":	(: tree :),
		"石苔":		(: tree :),
		"青萝":		(: tree :),	
		"lichen":	(: tree :),
      ]) );   


    set("outdoors", "xiangsi");

    set("coor/x",0);
    set("coor/y",0);
    set("coor/z",-10);
    setup();
}


void init()
{
    add_action("do_jump", ({"jump","dash"}));
    add_action("do_pick", ({"cut","pick"}));
    add_action("do_search", ({"search"}));
}


int do_jump(string arg)
{

    object me, room;
    int m;

    me = this_player();
    m = me->query_skill("move",1);

    if(!arg || (arg != "up" && arg != "上" && arg!= "bridge" && arg!="石梁" && arg!="ridge")) {
	write("你没法儿向那里跳。\n");
	return 1;
    }

    if (m >= 70)
    {  
	if (me->query("force") >= me->query("max_force")){
	    message_vision(CYN"$N提一口气，纵身向石梁上跃去。\n"NOR,me);
	    room = load_object(__DIR__"liangjie");
	    me->move(room);
	    message("vision", me->name()+"从虎踞石上纵了上来。\n", environment(me), me);
	    return 1;
	}else {
	    tell_object(me, "你的真气不够，怕还跳不上去。\n");
	    return 1;
	}
    }else {
	tell_object(me, "以你的轻身功夫，怕还跳不上去（需要７０级）\n");
	return 1;
    }
    return 1;
}


string tree()
{
    object me;
    int i;
    me = this_player();
    if (query("opened"))
    {
		tell_object(me, "山壁上爬满了喜湿的青萝石苔。\n");
		return "";
    }
    tell_object(me, "山壁上爬满了喜湿的青萝石苔，你注意到有一块地方的石苔分外厚重。\n");
    me->set_temp("annie/xiangsi_huju",1);
    return "";
}

void reset(){
    ::reset();
    set("opened", 0);
}




int do_pick(string arg)
{

    object me, tea;

    me = this_player();

    if (query("opened") || !me->query_temp("annie/xiangsi_huju"))
    {
		write("你胡乱抓了抓，抓了一手泥巴。\n");
		return 1;
    }

    if(!arg || (arg != "青苔" && arg != "lichen" && arg!= "石苔"))
    {
		write("你要削什么？\n");
		return 1;
    }

    set("opened",1);

    tea = new(__DIR__"obj/lichen");
    tea->move(me);
    message_vision(CYN"$N小心翼翼地自山壁上削下一些青苔。\n"NOR,me);
    tell_object(me, "削去了浮于外表的青苔，你觉得有一个约莫手掌大小的空间隐于苔下。\n");
    me->set_temp("annie/xiangsi_huju",2);
    return 1;
}


int do_search(string arg)
{
    object me = this_player();
    if (me->query_temp("annie/xiangsi_huju") != 2)
    {
		write("你胡乱找了找，什么也没找到。\n");
		return 1;
    }

    if (me->is_busy())
    {
		write("你现在正忙。\n");
		return 1;
    }

    tell_object(me,"你伸手小心翼翼地在苔下的空洞中摸索。\n");
    tell_object(me,"你什么也没有摸到。\n");

    me->perform_busy(1);
    return 1;
}
