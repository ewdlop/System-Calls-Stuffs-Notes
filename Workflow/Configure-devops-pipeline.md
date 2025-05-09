## Source
https://learn.microsoft.com/en-us/azure/developer/azure-developer-cli/configure-devops-pipeline?tabs=GitHub

##
Here's the corrected Markdown formatting for the YAML file, keeping the indentation and syntax intact for clarity.

```yaml
on:
  workflow_dispatch:
  push:
    # Run when commits are pushed to mainline branch (main or master)
    # Set this to the mainline branch you are using
    branches:
      - main
      - master

# Set this permission if you are using a Federated Credential.
permissions:
  id-token: write
  contents: read

jobs:
  build:
    runs-on: ubuntu-latest
    # azd build-in variables.
    # These variables are always set by `azd pipeline config`
    # You can set them as global env (apply to all steps) or you can add them to individual steps' environment
    env:
      AZURE_CLIENT_ID: ${{ vars.AZURE_CLIENT_ID }}
      AZURE_TENANT_ID: ${{ vars.AZURE_TENANT_ID }}
      AZURE_SUBSCRIPTION_ID: ${{ vars.AZURE_SUBSCRIPTION_ID }}
      AZURE_ENV_NAME: ${{ vars.AZURE_ENV_NAME }}
      AZURE_LOCATION: ${{ vars.AZURE_LOCATION }}
      # Define the additional variables or secrets that are required globally (provision and deploy)
      # ADDITIONAL_VARIABLE_PLACEHOLDER: ${{ variables.ADDITIONAL_VARIABLE_PLACEHOLDER }}
      # ADDITIONAL_SECRET_PLACEHOLDER: ${{ secrets.ADDITIONAL_SECRET_PLACEHOLDER }}
      
    steps:
      - name: Checkout
        uses: actions/checkout@v4

      # Using the install-azd action
      - name: Install azd
        uses: Azure/setup-azd@v1.0.0

      # If you want to use azd-daily build, or install it from a PR, you can remove previous step and
      # use the next one:
      # - name: Install azd - daily or from PR
      #   run: curl -fsSL https://aka.ms/install-azd.sh | bash -s -- --version daily
      #   shell: pwsh

      # azd set up Federated Credential by default. You can remove this step if you are using Client Credentials
      - name: Log in with Azure (Federated Credentials)
        if: ${{ env.AZURE_CLIENT_ID != '' }}
        run: |
          azd auth login `
            --client-id "$Env:AZURE_CLIENT_ID" `
            --federated-credential-provider "github" `
            --tenant-id "$Env:AZURE_TENANT_ID"
        shell: pwsh

      # If you set up your pipeline with Client Credentials, remove previous step and uncomment this one
      # - name: Log in with Azure (Client Credentials)
      #   if: ${{ env.AZURE_CREDENTIALS != '' }}
      #   run: |
      #     $info = $Env:AZURE_CREDENTIALS | ConvertFrom-Json -AsHashtable;
      #     Write-Host "::add-mask::$($info.clientSecret)"

      #     azd auth login `
      #       --client-id "$($info.clientId)" `
      #       --client-secret "$($info.clientSecret)" `
      #       --tenant-id "$($info.tenantId)"
      #   shell: pwsh
      #   env:
      #     AZURE_CREDENTIALS: ${{ secrets.AZURE_CREDENTIALS }}

      - name: Provision Infrastructure
        run: azd provision --no-prompt
        env:
          # Uncomment this if you are using infrastructure parameters
          # AZD_INITIAL_ENVIRONMENT_CONFIG: ${{ secrets.AZD_INITIAL_ENVIRONMENT_CONFIG }}
          # Define the additional variables or secrets that are required only for provision
          # ADDITIONAL_VARIABLE_PLACEHOLDER: ${{ variables.ADDITIONAL_VARIABLE_PLACEHOLDER }}
          # ADDITIONAL_SECRET_PLACEHOLDER: ${{ secrets.ADDITIONAL_SECRET_PLACEHOLDER }}

      - name: Deploy Application
        run: azd deploy --no-prompt
        env:
          # Define the additional variables or secrets that are required only for deploy
          # ADDITIONAL_VARIABLE_PLACEHOLDER: ${{ variables.ADDITIONAL_VARIABLE_PLACEHOLDER }}
          # ADDITIONAL_SECRET_PLACEHOLDER: ${{ secrets.ADDITIONAL_SECRET_PLACEHOLDER }}
```

This preserves the structure and syntax while providing the corrected Markdown format. If you need further edits or explanations on specific parts, let me know!
