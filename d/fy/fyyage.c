inherit ROOM;
void close_path();

void create()
{
    set("short", "风云雅阁");
    set("long", @LONG
这里专门招待江湖上万儿极响亮的人物。能有幸坐在这的，不是一掷千金的豪
客，就是跺跺脚江湖四颤的一方霸主。整间房子的中央只有一张上等翠玉打磨成的
八仙桌，桌上放着四只御赐金杯。三面的墙上挂满了字画，剩下的一面是一道一垂
及地的[33m红布挂帘[32m。
LONG
    );
    set("exits", ([
	"down" : __DIR__"fyge",
	"east" : __DIR__"fysf",
      ]));
    set("objects", ([
				__DIR__"npc/servant": 1,
				__DIR__"npc/tatoo": 1,
	//			AREA_GUANWAI"npc/champion": 1,

      ]) );
    set("item_desc", ([
	"curtain": "这个红布挂帘似乎可以掀开(open)。\n",
	"挂帘" : 	"这个红布挂帘似乎可以掀开(open)。\n",
	"红布挂帘" : "这个红布挂帘似乎可以掀开(open)。\n"
      ]) );
//    set("NONPC",1);
    set("coor/x",40);
    set("coor/y",40);
    set("coor/z",10);
    setup();
}

void init()
{
    add_action("do_open", "open");
}

void close_path()
{
    if( !query("exits/north") ) return;
    message("vision","红布挂帘又落了下来，盖住了暗门。\n",this_object() );
    delete("exits/north");
}


int do_open(string arg)
{
    object me;
    me = this_player();
    if( !arg || arg=="" ) return 0;

    if( arg=="curtain" || arg =="红布挂帘" || arg=="挂帘") {
	write("你掀开红布挂帘，");
	if( (int) me->query("force_factor") >= 100 )	{
	    write("推开了后面向北的一扇暗门。\n");
	    if( !query("exits/west") ) {
		set("exits/north", __DIR__"fysecret");
		call_out("close_path", 5);
	    }
	    return 1;	
	}	else
	    write("试着推了推后面的暗门，但没有推开。\n");
	return 1;
    }
    write("你要掀开什么？\n");
}



void init_scenery()
{
    object tie;
    tie = present("royal servant", this_object());
    if (tie) {        
	if (tie->query("in_meihuadao")) {
	    tie->delete("in_meihuadao");
	    tie->delete("no_heal");
	    return;
	} else {
	    CHANNEL_D->do_sys_channel("info",sprintf("%s，铁传甲追袭梅花盗未果，中桃花瘴重伤而归。", NATURE_D->game_time()));
	    tie->set("in_meihuadao",1);
	    tie->set("eff_kee",tie->query("max_kee")/2);
	    tie->set("eff_gin",tie->query("max_gin")/2);
	    tie->set("eff_sen",tie->query("max_sen")/2);
	    tie->set("no_heal",1);
	}
    }
    return;	
}

