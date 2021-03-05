
inherit ROOM;
void midnight_event();
void sunrise_event();
void create()
{
        set("short", "黄土路");
        set("long", @LONG
跟北面景色截然不同，这里是丘陵地带，四周充满了绿意，路旁不时有一块块
农人开垦出来的田地，向南望只见山峰秀丽挺拔一片苍翠，一条小土路绕过丘陵蜿
蜒的向南方伸展。
LONG
        );
    set("exits", ([ 
  		"north" : __DIR__"road3",
  		"south" : __DIR__"shanmen",
	]));
   
    set("outdoors", "huashan");

	set("coor/x",5);
	set("coor/y",25);
	set("coor/z",-40);
    NATURE_D->add_day_event(20, 2, this_object(), (: midnight_event :)); 
	setup();

}
void midnight_event() {
	object badguy;
	object room = this_object();
	int i, bandit_no = 1 + random(2);
	
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

