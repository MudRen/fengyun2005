inherit ITEM;
inherit F_LIQUID;

void create()
{
    set_name("红高粱", ({ "gaoliang skin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "一个牛皮缝的大酒袋，大概装得八、九升的高梁酒，是杏花村
专用武当山下的红高粱制成，名闻遐迩。\n");
		set("unit", "个");
       	set("value", 20000);
		set("max_liquid", 15);
	}
	set("liquid", ([
		"type": "alcohol",
   		"name": "红高粱",
		"remaining": 15,
       	"drunk_apply": 30,
	]) );
	::init_item();
}
