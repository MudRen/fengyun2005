inherit "/d/fycycle/obj/tutor";

void create()
{
        set_name("山峦", ({ "山峦","hill", "shanluan" }));  
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("unit", "");
		set("long",
			"山势如虎，雄霸一方，张牙舞爪，作势欲扑，灵动洒脱，矫捷无伦，似乎能悟
到一门高深的武功（tigerstrike）。\n");
		set("value", 70);
		set("material", "wood");
		set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);
 		set("teaching", "tigerstrike");
 		set("teaching_limit", 200);
 	}
 	
 }
 
 