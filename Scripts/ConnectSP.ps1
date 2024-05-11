
# Valid Colors: Black, DarkBlue, DarkGreen, DarkCyan, DarkRed, DarkMagenta, DarkYellow, 
#               Gray, DarkGray, Blue, Green, Cyan, Red, Magenta, Yellow, White
function Write-Yellow($message) {
    Write-Host $message -ForegroundColor "Yellow"
}
# SharePoint Site Data
$spEmpresa = "appsurgicorp"
$spSite = "AppStockInventarios"
$spListName = "BBDD_STOCK_INV"
$spUrl = "https://$spEmpresa.sharepoint.com/sites/$spSite/"
$spClientId = "50e9c267-2992-4b87-9f5b-221430ec4a2f"
$spThumbPrint = "9BC8DC618818698BB996CF0183C155A8ECAF6B05"
$spQuery = "<View>
                <ViewFields>
                    <FieldRef Name='ID'/>
                    <FieldRef Name='Title'/>
                </ViewFields>
                <Query>
                    <Where>
                        <Lt>
                        <FieldRef Name='ID'/>
                            <Value Type='Number'>
                                4000
                            </Value>
                        </Lt>
                    </Where>
                </Query>
            </View>"
            
# Connect to PnP Online Using ENTRA: 
Connect-PnPOnline -Tenant appsurgicorp.onmicrosoft.com -ClientId $spClientId -Thumbprint $spThumbPrint -Url $spUrl

$start = Get-Date
# Get List Items 
$spListItems =  Get-PnPListItem -List $spListName -PageSize 4000 -Query $spQuery
$end1 = Get-Date
$totaltime = $end1 - $start
$deleted = 0
Write-Yellow "`nTiempo de Get-ListItem: $($totaltime.tostring("hh\:mm\:ss"))"

# Deletes the Sharepoint List
$option = Read-Host "Desea Borrar la Lista '$spListName'? (Si / No)"
if($option -contains "S"){
    # Checks if list is empty
    if($spListItems.Count -eq 0 || $null -eq $spListItems) {
        Write-Host "No hay datos en la tabla: $spListName." -ForegroundColor "Red"
    } else {

        # Create a New Batch
        $Batch = New-PnPBatch
        
        # Delete All List Items
        ForEach($Item in $spListItems)
        {   
            Remove-PnPListItem -List $spListName -Identity $Item.ID -Batch $Batch
            $Item = $Item.ID
            $deleted++
            Write-Host "ID:$Item Deleting" -ForegroundColor "Blue"
        }
        
        # Send Batch to the server
        Invoke-PnPBatch -Batch $Batch
        Write-Yellow "`nItems Deleted    = $deleted"
        Write-Host "Deleted from $spListName Sharepoint List" -ForegroundColor "Green"

        $end2 = Get-Date
        $totaltime = $end2 - $start
        Write-Yellow "`nTiempo de Total: $($totaltime.tostring("hh\:mm\:ss"))"
    }
}