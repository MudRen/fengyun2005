// clean_up.c
// by Annihilator@ES2
// last modified by annie,25-11-2004

int clean_up()
{
	object *inv;
	int i;

//	if( !clonep() && this_object()->query("no_clean_up") ) return 1;
	if( this_object()->query("no_clean_up") ) return 1;

	if(interactive(this_object())) return 1;

	// If we are contained in something, let environment do the clean
	// up instead of making recursive call. This will prevent clean-up
	// time lag.
	if(environment()) return 1;

	if (this_object()->query("perma_exist"))	return 1;	// FORCE EXISTing ROOM such as boss room
		
	inv = all_inventory();
	for(i=sizeof(inv)-1; i>=0; i--)
	{
		if(interactive(inv[i])) return 1;
//		if(interactive(inv[i])->query("no_clean_up") ) return 1;
	}

	destruct(this_object());
	return 0;
}
