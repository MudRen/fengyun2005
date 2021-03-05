// Tie@fy3
inherit ROOM;

void create()
{
	set("short", "练武室");
	set("long", @LONG
这里是训练技能的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"down" : __DIR__"jobroom",
		"up":	"/d/darkfy/prep",
	]));
        set("valid_startroom", 1);

#ifdef NONENCRYPTED_WRITE	
        set("objects", ([
                __DIR__"npc/npc5m" : 1,
                __DIR__"npc/npc10m" : 1,
                __DIR__"npc/xian2" : 1,
                __DIR__"obj/sword":	1,
                __DIR__"obj/staff":	1,
                __DIR__"obj/hammer":	1,
                __DIR__"obj/axe":	1,
                __DIR__"obj/dart":	1,
                __DIR__"obj/spear":	1,
                __DIR__"obj/whip":	1,
                __DIR__"obj/blade":	1,
                __DIR__"obj/claw":	1,
                "/d/fycycle/npc/meida": 1,
                __DIR__"npc/mother": 1,
                __DIR__"npc/npc6m": 1,
         ]) );
#endif

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",20);
	setup();
}

int tttest(){
	object ob;
	
	ob=find_object("/obj/dungeon/standardmaze/"+this_player()->query("id"));
	
	if (ob)	return 1;	
	return 0;
	
}


int ttest(){
	if (4&4) tell_object(this_player(),"xx\n");
	return (1&2);
}

int testt(int i, object me) {
	tell_object(me,"time "+i+" is "+ time()+"\n");
	return 1;
}

int test(string arg){
	string *x = ({ "123.28", "123.78.22.*", "23.144.*" });
      object me = this_player();
	int i;
	string *y;
	
	y =({});
	y += ({"144.32.12.22"});
	
	for (i=0;i<sizeof(x);i++) {
		if (sizeof(regexp(y,x[i])) == 1
			&& y[0][0..2] == x[i][0..2]
			) {
			write (x[i]+"\n");
			return 1;
		}
	}
		
	write("nope\n");

	
	tell_object(me,"time is "+ time()+"\n");
	for(i=10;i>-1;i--){
		call_out("testt",i,i,me);
	}
	return 1;
}




	
int test2(){
	object attacker = this_player();
	object *inv, *pet;
	int i;
	
	inv = all_inventory(environment(attacker));
	write(sprintf("%O\n",inv));
	pet = filter_array(inv,(: !userp($1) && $1->query("possessed")==$2 :),attacker);
		
	write(sprintf("%O\n",pet));
				if (sizeof(pet))
				for (i=0;i<sizeof(pet);i++)
					pet[i]->die();
	return 1;
}

int *test3(){
	int *x = ({ 3, 4, 5 });
	return x;
}