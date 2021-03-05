inherit ROOM;
void create()
{
    set("short", "镖局内院");
    set("long", @LONG
一间北方常见的四合小院，是金狮镖局的镖头伙计们辛苦之余，休息放松的地
方。周围有几间青瓦小房，是供没有家的年青伙计们住的。院子的中央横七竖八的
架着几根[33m竹竿[32m，东北角的地上杂乱地堆着些[33m竹席[32m。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"ghall",
	"east"  : __DIR__"gke1", 
	"north" : __DIR__"gke2",
	"south" : __DIR__"gke3",
      ]));
    set("item_desc", ([
	"bamboo": 	"这些竹竿好象可以挪动（move bamboo）。\n",
	"竹竿" : 	"这些竹竿好象可以挪动（move bamboo）。\n",
	"几根竹竿" : 	"这些竹竿好象可以挪动（move bamboo）。\n",
	"竹席":		"破破烂烂的竹席上积满了灰尘，好久没人清理过了（move 竹席）。\n",
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",200);
    set("coor/y",-60);
    set("coor/z",0);
    set("map","fyeast");
    setup();
}

void init()
{
    add_action("do_move", "move");
}

int do_move(string arg)
{
    object cock, me, room;

    me = this_player();

    if ( arg == "bamboo" || arg == "竹竿" || arg == "几根竹竿") {
	if (me->is_busy())
	    return notify_fail("你现在正忙。\n");
	me->perform_busy(1);

	if( query("amount") > 10 ) 
	    return notify_fail("还挪？！蟑螂都被你吓的跑光了。\n" );
	cock = new(__DIR__"npc/cockroach");
	if(cock) {
	    cock->move(this_object());
	    message_vision("$N挪了下竹竿，一只"+cock->name()+"飞快地爬了出来．\n", this_player());
	}
	add("amount",1);
	return 1;
    }
    if ( arg == "竹席") {
	if (me->query_temp("marks/js_cook_mice") < 4) {
	    message_vision("$N挪了挪竹席，闹得满院子是灰。\n",me);
	    return 1;
	}
	if (me->query_temp("marks/js_cook_move")<3) {
	    me->add_temp("marks/js_cook_move",1);
	    message_vision("$N拉起一张竹席，下面空空荡荡，只有扑面的灰尘。。\n",me);
	    return 1;
	}
	me->delete_temp("marks/js_cook_move");
	me->delete_temp("marks/js_cook_mice");
	if ( !objectp(room = find_object(__DIR__"mice_room0")))
	    room = load_object(__DIR__"mice_room0");
	message_vision("$N用力一拉竹席，没料到脚下一滑，扑通摔在地上。\n",me);
	me->unconcious();
	me->move(room);
	return 1;
    }

    return notify_fail("你要搬动什么？\n");
}

void reset()
{
    ::reset();
    set("amount",0);
}
