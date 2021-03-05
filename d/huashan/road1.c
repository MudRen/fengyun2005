
inherit ROOM;
void midnight_event();
void sunrise_event();
void create()
{
        set("short", "荒野");
        set("long", @LONG
这是一个无边的荒野地，平坦的地势让人一眼望不到边际，地面上布满了沙石
土块，一条黄土路笔直的伸向西方，路旁的地生长着一丛丛的灌木杂草，灰黑色的
叶片给你一种沉重郁闷的感觉。
LONG
        );
    set("exits", ([ 
  		"west" : __DIR__"road2",
        "southeast" : AREA_CHENXIANG"road",
	]));
   
    set("outdoors", "huashan");

	set("coor/x",15);
	set("coor/y",30);
	set("coor/z",-40);
    NATURE_D->add_day_event(20, 2, this_object(), (: midnight_event :)); 
	setup();
}

void midnight_event() {
	object badguy;
	object room = this_object();
	int i, bandit_no = 2 + random(3);
	
	if(!random(10)) {
        for(i=0; i<bandit_no; i++) {
            if(objectp(badguy = new("/obj/npc/bandit"))) {
                badguy->setup_bandit("土匪喽罗", "/obj/armor/cloth", "/obj/weapon/blade_guitou", "huashan");
                badguy->move(room);
            }
        }
        NATURE_D->add_day_event(3, 1, this_object(), (: sunrise_event :));
	} else {
	    NATURE_D->add_day_event(20, 2, this_object(), (: midnight_event :));
	}
}

void sunrise_event() {
    object *ob_list;
    int i;
    
    ob_list = children("/obj/npc/bandit");
    for(i=0; i<sizeof(ob_list); i++) {
            if(ob_list[i]->query("area_mark") == "huashan") {
                    if(environment(ob_list[i])) {
                            message_vision("$N叫道：天晓也，扯乎！\n",ob_list[i]);
                    }
                    destruct(ob_list[i]);
            }
    }
    NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
}
