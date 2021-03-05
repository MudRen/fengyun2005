inherit DOOR_ROOM;
#include <room.h>

void create()
{
    set("short", "金狮镖局大厅");
    set("long", @LONG
大红[33m地毯[32m依旧，珍奇古玩，高悬字画，表明这里的主人不但性情豪爽，广交朋
友，且非大字不识，目中无人之辈。上首一狮皮交椅，左右各明烛闪烁。一深色古
木书案横于椅前，上面整齐的堆着一卷卷镖局押镖的货票。向北一道铁门。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"goldlion",
	"east" : __DIR__"ginhall",
	"north" : __DIR__"gmoney",
      ]));
    set("objects", ([
	__DIR__"npc/gmaster" : 1,
      ]) );

    set("item_desc", ([
	"字画":		"这字画。。。马马虎虎吧，大部分是临摹的。\n",
	"狮皮交椅":	"这是镖局总镖头查猛最爱坐的椅子，打扫得干干净净。\n",
	"珍奇古玩":	"这是查猛二十多年积攒下来的。\n",
	"书案":		"书案横于椅前，上面整齐的堆着一卷卷镖局押镖的货票。\n",
      ]));

    set("coor/x",180);
    set("coor/y",-60);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    create_door("north", "door","铁门", "south", DOOR_CLOSED);

}

void init(){
    add_action("do_look","look");
}


int do_look(string arg){
    object me;

    me = this_player();


    if (arg == "地毯" || arg == "rag" || arg == "carpet" || arg == "大红地毯") {
	if (this_player()->query_temp("marks/js_cook_mice") < 3) {
	    tell_object(this_player(),"大厅的地面上铺着大红地毯，把屋子里的气氛烘托得暖洋洋的。\n");
	    return 1;
	}
	tell_object(this_player(),"大厅的地面上铺着大红地毯，把屋子里的气氛烘托得暖洋洋的。\n");
	tell_object(this_player(),"奇怪的是，干干净净的毯子上掉了几粒米饭。\n");
	this_player()->set_temp("marks/js_cook_mice",4);
	return 1;
    }

    return 0;
}
