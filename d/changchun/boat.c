// boat.c
inherit ROOM;
void create()
{
        set("short", "渔船中");
        set("long", @LONG
舱中光线昏暗，船头站着一个白发苍苍的老妇人，她年龄虽已老迈，但站在动
荡的船头上，强劲的海风间，身子却仍挺得笔直，似是一生从未曾弯曲过。
LONG
        );
        set("objects",([
        	AREA_TIEFLAG"npc/boater" : 1,
		]));
	set("coor/x",1420);
	set("coor/y",-410);
	set("coor/z",-30);
	set("no_fly",1);
	set("no_lu_letter",1);
	setup();
}   

void boat_run(int counter)
{
	object dest;
	object *inv;
	int i;
	
	inv=all_inventory(this_object());
	if (!present("old boater",this_object()))
	{
		for(i=0;i<sizeof(inv);i++)
			if(userp(inv[i]))
			{
				message("vision","小船无人驾驶，在海面上漫无目的的飘荡...\n",this_object());
				call_out("boat_run",20,counter);  
				return;
			}
		remove_call_out("boat_run");
	}
			
	for (i=0;i<sizeof(inv);i++)
	    if (userp(inv[i]))
		{
	
			switch(counter){
			case 0 :	
  		  	message("vision","小船轻轻晃动，缓缓向前驶去。\n",this_object());
				break;
			case 1 :  
		        message("vision","但闻水声荡荡，海天俱寂。\n",this_object());
				break;
		    case 2 :
		    	message("vision","老婆子长篙一点，小船转了一个方向。\n",this_object());
				break;
		    case 3 :
		    	message("vision", "茫茫大海，你不知还要走多久。\n",this_object());
				break;
		    case 4 :
		    	if (query_temp("mark/dest")=="island")
		    		message("vision", "海天一线处出现了一个黑点，黑点越来越大，你发现那是一个小岛。\n",this_object());
			    else
			    	message("vision", "海天一线处出现了一条黑影，黑影越来越近。\n",this_object());
	    		break;
		    case 5 :
    			message("vision","老婆子说道：“到了，你们可以下船了。”\n",this_object());
			    if (query_temp("mark/dest")=="island")
			    {
			    	set("exits/up",__DIR__"island");
					if (!objectp(dest=find_object(__DIR__"island")))
						dest=load_object(__DIR__"island");
					set_temp("mark/dest","mainland");
				} 
			    else
			    {
			    	set("exits/up",AREA_EASTCOAST"seaside");
	    			if (!objectp(dest=find_object(AREA_EASTCOAST"seaside")))
						dest=load_object(AREA_EASTCOAST"seaside");
					set_temp("mark/dest","island");
			    } 
			    dest->set("exits/down",AREA_CHANGCHUN"boat");
			    message("vision","一条小船缓缓驶了过来。\n",dest);
			    call_out("leave",10,dest);
			    return;
			} 
	
			call_out("boat_run",5,counter+1);
			return;
		}
}
void leave(object dest)
{
	object *inv;
	object oob;
	int i;
	if (!objectp(oob=present("old boater",this_object())) || !living(oob))
	{
		call_out("leave",20,dest);
		return;
	}
	inv=all_inventory(this_object());		
	for (i=0;i<sizeof(inv);i++)
	    if (userp(inv[i]))
		{
            message("vision","老婆子长篙一点，小船又驶了回去。\n",dest);
            message("vision","老婆子长篙一点，小船又驶了回去。\n",this_object());
        	delete("exits/up");
        	dest->delete("exits/down");
        	call_out("boat_run",5,0);
        	return;                    
        }
    message("vision","老婆子长篙一点，小船又驶了回去。\n",dest);          
	delete("exits/up");
	dest->delete("exits/down");
        
    return;
}
