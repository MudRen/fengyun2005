#include <ansi.h>
inherit ROOM;

int do_suli();
void load_item(object me);

void create()
{
    set("short", "忏悔间");
    set("long", @LONG
一间只容一个人的小房间。房间的一面墙上有孔，这里的声音可以很清晰的传
到隔壁。房间里只有张小木凳和钉在墙上供人放东西的木板，无论你做了多大的罪
孽，或是心里藏了什么龌龊的念头，只要肯在这里真诚忏悔（ｐｒａｙ）就能洗心
革面，丢弃一切尘世俗物的牵挂，重新做人。如果你丢了什么重要的东西，也可以
来祷告一番，祈求上苍的恩赐。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"church",
      ]));
    set("objects", ([
	__DIR__"npc/chantou" : 1,
      ]) );
    set("coor/x",20);
    set("coor/y",-70);
    set("coor/z",0);
    set("map","fysouth");
    setup();
}

int	init() {
	add_action("do_suli","pray");
}


int	do_suli(){
	object me;
	me = this_player();
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
	message_vision(YEL"$N毕恭毕敬地跪下，双手团在胸前，低着头开始忏悔。\n"NOR,me);
	tell_object(me,"你划着十字发誓：我我我今后一定小心不再丢东西了。。。\n");
	me->start_busy(3);
	call_out("load_item",4,me);
	return 1;
}


void load_item(object me)
{
	int MAX = 3;
	string name,id, *created, my_item, inv_item;
	int j, i, got_one;
	object thing, *inv;

	id = me->query("id");
	if (!objectp(me) 
		|| environment(me)!=this_object() 
		|| me->is_ghost())
		return;

	created = get_dir(DATA_DIR + "login/" + id[0..0] + "/" + id + "/");
	for(j=0; (j<sizeof(created) && j < (MAX+1) ); j++)
	if( sscanf(created[j], "%s.c", name) == 1 )
		{
			got_one = 0;
			my_item = DATA_DIR + "login/" + id[0..0] + "/" + id + "/" + name + ".c";
			inv = all_inventory(me);
			i = sizeof(inv);		
			if (i>=14)	return;	//以免东西太多出错，干脆就不给了。
			while (i--) {
				if(inv[i]->query("weapon_prop") && inv[i]->query("owner") == id ) {
					inv_item = base_name(inv[i])+".c";
					if (inv_item == my_item) 
						got_one = 1;
				}
			}
			if (!got_one) {	
				thing = new(my_item);
				thing->restore();
		
/*		thing->set("weapon_prop/karma",me->query("imbue_prop/karma"));
		thing->set("weapon_prop/composure",me->query("imbue_prop/composure"));
		thing->set("weapon_prop/strength",me->query("imbue_prop/strength"));
		thing->set("weapon_prop/agility",me->query("imbue_prop/agility"));
		thing->set("weapon_prop/intelligence",me->query("imbue_prop/intelligence"));*/

				// *sing*

				if(thing->move(me))  
					message_vision( thing->name() + "一闪，跃现在$N手中！！\n",me);
					else write("error when moving to player.\n");
			}
		}
	me->set_temp("already_loaded",1);
	message_vision("$N忏悔完毕，诚惶诚恐地站起身来。\n",me);
}